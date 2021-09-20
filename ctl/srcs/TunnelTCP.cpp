//
// Created by Guillaume on 12/09/2021.
//

#include "TunnelTCP.hpp"

// Default constructor
TunnelTCP::TunnelTCP() : _port(TUNNEL_PORT) {}

// Port constructor
[[maybe_unused]] TunnelTCP::TunnelTCP(int port) : _port(port) {}

// Copy constructor
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
t_tunnel_tcp_error TunnelTCP::setError(const std::string &error, t_tunnel_tcp_error error_type) {
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
		return (setError("Socket options initialization failed", SOCK_OPT_ERR));
    if (connect(_socket, (sockaddr *)&_address, sizeof(_address)) < 0)
        return (setError("Connection failed", CONN_ERR));
    else
    	return (NO_ERR);
}

// Enable connection
void TunnelTCP::start() {
	std::cout << "[TunnelTCP]: Start thread" << std::endl;
	_thread_state = true;
	_thread = new std::thread(&TunnelTCP::run, this);
	std::cout << "[TunnelTCP]: Connection established on port [" << TUNNEL_PORT << "]" << std::endl;
}

// Disable connection
[[maybe_unused]] void TunnelTCP::stop() {
	std::cout << "[TunnelTCP]: Stop thread" << std::endl;
	_thread_state = false;
	_thread->join();
	delete _thread;
}

// Restart connection
[[maybe_unused]] void TunnelTCP::restart() {
	stop();
	start();
}

/**
 * @brief Add data to client buffer
 *
 * @param data
 */
void TunnelTCP::addData(const std::string &data) {
    _emission_buffer += data;
}

/**
 * @brief Send data to client
 *
 * @param fd
 */
void TunnelTCP::sendData(int fd) {
    if (_emission_buffer != "") {
        std::cout << "[TunnelTCP]: Send : [" << _emission_buffer << "]" << std::endl;
        size_t len = send(fd, _emission_buffer.c_str(), strlen(_emission_buffer.c_str()), 0);
        _emission_buffer = _emission_buffer.substr(len);
    }
}

// Function called by thread for handle connections
void TunnelTCP::run() {
	fd_set curr_set;
	fd_set rd_set;
	fd_set wr_set;

	fcntl(_socket, F_SETFL, O_NONBLOCK);

	FD_ZERO(&curr_set);
	FD_SET(_socket, &curr_set);
	while (_thread_state) {
		wr_set = rd_set = curr_set;
		if (select(FD_SETSIZE + 1, &rd_set, &wr_set, nullptr, nullptr) < 0)
			continue;
		for (int fd = 0; fd < FD_SETSIZE; fd++) {
			if (FD_ISSET(fd, &rd_set)) {
				std::cout << "[TunnelTCP]: " << fd << " is in rd_set" << std::endl;
                if (recv(fd, _reception_buffer, BUFFER_SIZE, 0) <= 0) {
                    // TODO Exit
                    std::cout << "[TunnelTCP]: Daemon disconnected" << std::endl;
					FD_CLR(_socket, &curr_set);
					close(_socket);
                    fatal("Daemon closed");
                } else {
				    std::cout << "[TunnelTCP]: Receive: [" << _reception_buffer << "]" << std::endl;
                    // TODO Treat data
                }
			}
            if (FD_ISSET(fd, &wr_set))
                sendData(fd);
		}
	}
}

// Destructor
TunnelTCP::~TunnelTCP() {
	stop();
	close(_socket);
	std::cout << "[TunnelTCP]: Destroyer called" << std::endl;
}
