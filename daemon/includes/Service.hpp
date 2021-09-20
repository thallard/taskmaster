//
// Created by Thomas Hallard-clot on 9/17/21.
//

#ifndef TASKMASTER_DAEMON_SERVICE_H
#define TASKMASTER_DAEMON_SERVICE_H

#include "global.hpp"

class Service {
private:
    std::thread *_thread;
    std::string _name;
    std::string _cmd;
    std::string _umask;
    std::string _chmod;

public:
    Service();
    ~Service();
    Service(Service const & ref);
    Service &operator=(Service const & ref);
    // Getters
    std::string const &getName() const { return _name; }

    // Setters
    void setName(std::string const & name) { _name = name; }
};


#endif //TASKMASTER_DAEMON_SERVICE_H
