//
// Created by Thomas Hallard-clot on 9/17/21.
//

#ifndef TASKMASTER_DAEMON_EXECUTION_HPP
#define TASKMASTER_DAEMON_EXECUTION_HPP
#include "global.hpp"
#include "Service.hpp"

class Service;

//TODO: Need to rename the class
class Execution {
private:
    std::list<Service *> _services;
    std::list<std::thread *> _threads;

public:
    Execution();
    ~Execution();

    bool addService(Service *);
    bool delService(std::string const & name);

    int getServicesCount();

};


#endif //TASKMASTER_DAEMON_EXECUTION_HPP
