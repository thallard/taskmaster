//
// Created by Thomas Hallard-clot on 9/17/21.
//

#ifndef TASKMASTER_DAEMON_EXECUTION_HPP
#define TASKMASTER_DAEMON_EXECUTION_HPP
#include "global.hpp"

class ServiceManager;
class Service;

//TODO: Need to rename the class
class Execution {
private:
    std::list<ServiceManager *> _managers;
    std::list<std::thread *> _threads;

public:
    Execution();
    ~Execution();

    bool addManager(ServiceManager *);
    bool delManager(std::string const & name);

    int getManagersCount();

};


#endif //TASKMASTER_DAEMON_EXECUTION_HPP
