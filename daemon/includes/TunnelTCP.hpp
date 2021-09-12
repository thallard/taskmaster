//
// Created by Guillaume on 12/09/2021.
//

#ifndef TASKMASTER_DAEMON_TUNNELTCP_HPP
#define TASKMASTER_DAEMON_TUNNELTCP_HPP

#include "global.hpp"

class TunnelTCP {
public:
    TunnelTCP();
    TunnelTCP(int);
    TunnelTCP(const TunnelTCP &);
    TunnelTCP &operator=(const TunnelTCP &);

    void connect();
    void disconnect();

    ~TunnelTCP();
private:
    int _port;
    int _socket;
};


#endif //TASKMASTER_DAEMON_TUNNELTCP_HPP
