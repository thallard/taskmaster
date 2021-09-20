//
// Created by Thomas Hallard-clot on 9/20/21.
//

#ifndef TASKMASTER_DAEMON_MANAGER_H
#define TASKMASTER_DAEMON_MANAGER_H
#include "global.hpp"

class Service;

class ServiceManager {
private:
    Service *_service;
    std::thread *_thread;

    ServiceManager();
public:
    explicit ServiceManager(Service *);
    ~ServiceManager();
    ServiceManager(ServiceManager const & ref);
    ServiceManager &operator=(ServiceManager const & ref);

    // Getters and setters
    Service const &getService() const;
    std::string const &getServiceName() const;
    void setService(Service *service);

    // Core commands
    void runService();

};


#endif //TASKMASTER_DAEMON_MANAGER_H
