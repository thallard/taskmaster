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
	return (_error = error_type);
}

// Initialization
t_tunnel_tcp_error TunnelTCP::init() {
    std::cout << "Init section" << std::endl;

	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	_address.sin_port = htons(_port);

	if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (setError("Socket initialization failed", SOCKET_ERR));
	if (bind(_socket, (sockaddr *)&_address, sizeof(_address)) < 0)
		return (setError("Bind socket failed", BIND_ERR));
	if (listen(_socket, 0) < 0)
		return (setError("Start listening failed", LISTEN_ERR));
	std::cout << "End init" << std::endl;
	return (NO_ERR);
}

// Enable connection
void TunnelTCP::start() {
	_thread_state = true;
	_thread = new std::thread(&TunnelTCP::run, this);
}

// Disable connection
void TunnelTCP::stop() {
	_thread_state = false;
	_thread->join();
	delete _thread;
	FD_ZERO(&_curr_set);
}

void TunnelTCP::run() {
	int new_fd;

	while (_thread_state) {
		_rd_set = _wr_set = _curr_set;
		if (select(_socket, &_rd_set, &_wr_set, NULL, NULL) < 0)
			continue;
		std::cout << "Here" << std::endl;
		for (int fd = 0; fd < FD_SETSIZE; fd++)
			if (FD_ISSET(fd, &_rd_set)) {
				if (fd == _socket) {
					if ((new_fd = accept(_socket, NULL, NULL)) < 0) {
						setError("Accept connection failed", ACCEPT_ERR);
						stop();
					}
					FD_SET(fd, &_curr_set);
					std::cout << "client just arrived" << std::endl;
				} else {
					if (recv(_socket, _reception_buffer, BUFFER_SIZE, 0) <= 0) {
						FD_CLR(fd, &_curr_set);
						std::cout << "client just left" << std::endl;
					} else {
						// Treat data
					}
				}
			}
	}

}

// Destructor
TunnelTCP::~TunnelTCP() {
	close(_socket);
}