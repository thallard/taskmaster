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
protected:

public:
   std::string const &getName() { return _name; }

};


#endif //TASKMASTER_DAEMON_SERVICE_H
