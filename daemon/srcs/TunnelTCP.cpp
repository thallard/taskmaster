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

// Enable connection
void TunnelTCP::connect() {

}

// Disable connection
void TunnelTCP::disconnect() {

}

// Destructor
TunnelTCP::~TunnelTCP() {}