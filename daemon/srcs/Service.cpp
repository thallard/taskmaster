//
// Created by Thomas Hallard-clot on 9/17/21.
//

#include "Service.hpp"

// Default constructor
Service::Service()
{
    _thread = nullptr;
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

// Threaded function called by ServiceManager, create an another thread for the service
void Service::runProcess()
{

    std::cout <<  "trhead" << std::endl;
    _thread = new std::thread(&Service::launchProcess, this);
    sleep(1);
    _thread->join();
    std::cout << "kill Service thread\n";
}

// Threaded function called by runProcess, launch the service
void Service::launchProcess()
{

    std::cout << "oui" << std::endl;


}