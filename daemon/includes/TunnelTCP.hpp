//
// Created by Guillaume on 12/09/2021.
//

#ifndef TASKMASTER_DAEMON_TUNNELTCP_HPP
#define TASKMASTER_DAEMON_TUNNELTCP_HPP

#include "global.hpp"

// List of possible errors
typedef enum e_tunnel_tcp_error {
	NO_ERR,
	SOCKET_ERR,
    BIND_ERR,
    LISTEN_ERR,
	ACCEPT_ERR,
	SOCKOPT_ERR
} t_tunnel_tcp_error;

class TunnelTCP {
public:
    TunnelTCP();
    TunnelTCP(int);
    TunnelTCP(const TunnelTCP &);
    TunnelTCP &operator=(const TunnelTCP &);

    e_tunnel_tcp_error init();
    void start();
    void stop();
	void restart();
	void run();

    ~TunnelTCP();

private:
    // Private functions
    t_tunnel_tcp_error setError(std::string error, t_tunnel_tcp_error error_type);

    // Properties
    int _port;
    int _socket;
	sockaddr_in _address;

	std::thread *_thread;
	bool _thread_state;

	fd_set _curr_set;
	fd_set _rd_set;
	fd_set _wr_set;

	char _reception_buffer[BUFFER_SIZE];
	char _emission_buffer[BUFFER_SIZE];

    t_tunnel_tcp_error _error;
};


#endif //TASKMASTER_DAEMON_TUNNELTCP_HPP
