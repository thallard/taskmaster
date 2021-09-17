
//
// Created by Guillaume on 12/09/2021.
//

#include "TunnelTCP.hpp"

// Default constructor
TunnelTCP::TunnelTCP() : _port(TUNNEL_PORT) {}

// Port constructor
TunnelTCP::TunnelTCP(int port) : _port(port) {}

// Copy contructor
TunnelTCP::TunnelTCP(const TunnelTCP &o) : _port(o._port), _socket(o._socket) {}

// Assignation operator
TunnelTCP &TunnelTCP::operator=(const TunnelTCP &o) {
    if (this == &o) return(*this);
    this->~TunnelTCP();
    return *new(this) TunnelTCP(o);
}

/**
 *
 * @param error Error description
 * @param error_type Error type
 *
 * @return Return the error type
 */
t_tunnel_tcp_error TunnelTCP::setError(std::string error, t_tunnel_tcp_error error_type) {
    std::cerr << "TunnelTCP Error : " << error << std::endl;
	_error = error_type;
	return (_error);
}

// Initialization
t_tunnel_tcp_error TunnelTCP::init() {
	int on = 1;
	std::cout << "[TunnelTCP]: Initialize connection" << std::endl;

	bzero(&_address, sizeof(_address));
	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = htonl(2130706433);
	_address.sin_port = htons(_port);

	if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (setError("Socket initialization failed", SOCKET_ERR));
	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &on,sizeof(on)))
		return (setError("Socket options initialization failed", SOCKOPT_ERR));
	if (bind(_socket, (const struct sockaddr *)&_address, sizeof(_address)) < 0)
		return (setError("Bind socket failed", BIND_ERR));
	if (listen(_socket, 0) < 0)
		return (setError("Start listening failed", LISTEN_ERR));
	return (NO_ERR);
}

// Enable connection
void TunnelTCP::start() {
	std::cout << "[TunnelTCP]: Start thread" << std::endl;
	_thread_state = true;
	_thread = new std::thread(&TunnelTCP::run, this);
	std::cout << "[TunnelTCP]: Connection etablished on port [" << TUNNEL_PORT << "]" << std::endl;
}

// Disable connection
void TunnelTCP::stop() {
	std::cout << "[TunnelTCP]: Stop thread" << std::endl;
	_thread_state = false;
	_thread->join();
	delete _thread;
}

// Restart connection
void TunnelTCP::restart() {
	stop();
	start();
}

/**
 * @brief Add data to client buffer
 *
 * @param fd
 * @param data
 */
void TunnelTCP::addData(int fd, const std::string data) {
    auto itr = _emission_buffer.find(fd);
    if (itr != _emission_buffer.end())
        itr->second += data;
}

/**
 * @brief Send data to client
 *
 * @param fd
 */
void TunnelTCP::sendData(int fd) {
    auto itr = _emission_buffer.find(fd);
    if (itr != _emission_buffer.end() && !itr->second.empty()) {
        std::cout << "[TunnelTCP]: Send : [" << itr->second << "]" << std::endl;
        size_t len = send(fd, itr->second.c_str(), strlen(itr->second.c_str()), 0);
        itr->second = itr->second.substr(len);
    }
}

// Function called by thread for handle connections
void TunnelTCP::run() {
	fd_set curr_set;
	fd_set rd_set;
	fd_set wr_set;
	int new_fd;

	fcntl(_socket, F_SETFL, O_NONBLOCK);

	FD_ZERO(&curr_set);
	FD_SET(_socket, &curr_set);
	while (_thread_state) {
		wr_set = rd_set = curr_set;
		if (select(FD_SETSIZE + 1, &rd_set, &wr_set, NULL, NULL) < 0)
			continue;
		for (int fd = 0; fd < FD_SETSIZE; fd++) {
			if (FD_ISSET(fd, &rd_set)) {
				std::cout << "[TunnelTCP]: " << fd << " is in rd_set" << std::endl;
				if (fd == _socket) {
					std::cout << "[TunnelTCP]: Client just arrived" << std::endl;
					if ((new_fd = accept(_socket, NULL, NULL)) < 0) {
						setError("Accept connection failed", ACCEPT_ERR);
						stop();
					}
					FD_SET(new_fd, &curr_set);
                    _emission_buffer.insert(std::pair<int, std::string>(new_fd, ""));
					break;
				} else {
                    bzero(_reception_buffer, BUFFER_SIZE);
					if (recv(fd, _reception_buffer, BUFFER_SIZE, 0) <= 0) {
						std::cout << "[TunnelTCP]: Client just left" << std::endl;
						FD_CLR(fd, &curr_set);
                        std::cout << "[TunnelTCP]: Clear client [" << fd << "]" << std::endl;
                        _emission_buffer.erase(fd);
						close(fd);
						break;
					} else {
						std::cout << "[TunnelTCP]: Receive : [" << _reception_buffer << "]" << std::endl;
                        addData(fd, "pong\n");
                        // TODO Treat data
					}
				}
			}
            if (FD_ISSET(fd, &wr_set))
                sendData(fd);
		}
	}
	for (int fd = 0; fd <= FD_SETSIZE; fd++)
		if (FD_ISSET(fd, &curr_set))
			close(fd);
}

// Destructor
TunnelTCP::~TunnelTCP() {
	stop();
	close(_socket);
	std::cout << "[TunnelTCP]: Destroyer called" << std::endl;
}
