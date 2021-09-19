//
// Created by Guillaume on 12/09/2021.
//

#ifndef TASKMASTER_CTL_TUNNEL_TCP_HPP
#define TASKMASTER_CTL_TUNNEL_TCP_HPP

#include "global.hpp"

// List of possible errors
typedef enum e_tunnel_tcp_error {
	NO_ERR,
	SOCKET_ERR,
	ACCEPT_ERR,
	SOCK_OPT_ERR,
    CONN_ERR
} t_tunnel_tcp_error;

class TunnelTCP {
public:
    TunnelTCP();

    [[maybe_unused]] TunnelTCP(int);
    TunnelTCP(const TunnelTCP &);
    TunnelTCP &operator=(const TunnelTCP &);

    e_tunnel_tcp_error init();
    void start();
    void stop();

    [[maybe_unused]] [[maybe_unused]] void restart();
	void run();

    void addData(const std::string&);

    ~TunnelTCP();
private:
    // Private functions
    t_tunnel_tcp_error setError(const std::string& error, t_tunnel_tcp_error error_type);

    // Properties
    int _port = BUFFER_SIZE;
    int _socket{};
	sockaddr_in _address{};

	std::thread *_thread{};
	bool _thread_state{};

	char _reception_buffer[BUFFER_SIZE]{};
    std::string _emission_buffer;

    t_tunnel_tcp_error _error = t_tunnel_tcp_error::NO_ERR;

    void sendData(int fd);
};


#endif //TASKMASTER_CTL_TUNNEL_TCP_HPP
