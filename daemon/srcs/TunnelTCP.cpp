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

	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	_address.sin_port = htons(_port);

	if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (setError("Socket initialization failed", SOCKET_ERR));
	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &on,sizeof(on)))
		return (setError("Socket options initialization failed", SOCKOPT_ERR));
	if (bind(_socket, (sockaddr *)&_address, sizeof(_address)) < 0)
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

// Function called by thread for handle connections
void TunnelTCP::run() {
	int new_fd;
	struct timeval timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 100;

	(void) _emission_buffer;

	FD_SET(_socket, &_curr_set);
	while (_thread_state) {
		_rd_set = _wr_set = _curr_set;
		if (select(FD_SETSIZE, &_rd_set, &_wr_set, NULL, &timeout) < 0)
			continue;
		for (int fd = 0; fd < FD_SETSIZE; fd++)
			if (FD_ISSET(fd, &_rd_set)) {
				if (fd == _socket) {
					std::cout << "[TunnelTCP]: Client just arrived" << std::endl;
					if ((new_fd = accept(_socket, NULL, NULL)) < 0) {
						setError("Accept connection failed", ACCEPT_ERR);
						stop();
					}
					FD_SET(fd, &_curr_set);
				} else {
					if (recv(_socket, _reception_buffer, BUFFER_SIZE, 0) <= 0) {
						std::cout << "[TunnelTCP]: Client just left" << std::endl;
						FD_CLR(fd, &_curr_set);
					} else {
						// Treat data
						std::cout << "[TunnelTCP]: Treat data" << std::endl;
						send(fd, _reception_buffer, strlen(_reception_buffer), 0);
					}
				}
			}
	}
	FD_ZERO(&_curr_set);
}

// Destructor
TunnelTCP::~TunnelTCP() {
	close(_socket);
}