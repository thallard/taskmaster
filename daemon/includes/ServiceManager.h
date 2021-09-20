//
// Created by Thomas Hallard-clot on 9/20/21.
//

#ifndef TASKMASTER_DAEMON_MANAGER_H
#define TASKMASTER_DAEMON_MANAGER_H
#include "global.hpp"
#include "Service.hpp"
class Service;
class ServiceManager {
private:
    Service *_service;
    thread *_thread;
    string _nameService;

    ServiceManager();
public:
    explicit ServiceManager(Service *);
    ~ServiceManager();
    ServiceManager(ServiceManager const & ref);
    ServiceManager &operator=(ServiceManager const & ref);

    // Getters and setters
    Service const &getService() const { return *_service; }
    string const &getServiceName() const { return _nameService; }
    void setService(Service *service) { _service = service; }

    // Core commands
    void runService();

};


#endif //TASKMASTER_DAEMON_MANAGER_H
