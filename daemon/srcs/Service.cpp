//
// Created by Thomas Hallard-clot on 9/17/21.
//

#include "Service.hpp"


// Default constructor
Service::Service()
{
}

Service::~Service()
{
    delete _thread;
}

// Constructor per copy
Service::Service(Service const & ref)
{
    *this = ref;
}

// Overload operator=
Service &Service::operator=(const Service &ref)
{
    if (this == &ref)
        return *this;
    _thread = ref._thread;
    _name = ref._name;
    _cmd = ref._cmd;
    _umask = ref._umask;
    _chmod = ref._chmod;
    return *this;
}

// Thread function called by ServiceManager, create an another thread and launch the service
void Service::runProcess()
{
    std::cout <<  "trhead" << endl;
    //_thread = new thread(Service::launchProcess, this);
}

void *Service::launchProcess()
{
    cout << "oui" << endl;
    return nullptr;
}