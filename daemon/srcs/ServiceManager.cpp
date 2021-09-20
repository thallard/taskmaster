//
// Created by Thomas Hallard-clot on 9/20/21.
//

#include "ServiceManager.h"

// Default constructor
ServiceManager::ServiceManager()
{
   _service = nullptr;
}

// Constructor with Service assignation
ServiceManager::ServiceManager(Service *service)
{
    _service = service;
}

// Destructor
ServiceManager::~ServiceManager() {
    delete _thread;
    delete _service;
}

// Constructor per copy
ServiceManager::ServiceManager(const ServiceManager &ref)
{
    *this = ref;
}

// Overload operator=
ServiceManager &ServiceManager::operator=(const ServiceManager &ref)
{
    if (this == &ref)
        return *this;
    _thread = ref._thread;
    _service = ref._service;
    return *this;
}

// Run a specific program and start to manage it
void ServiceManager::runService()
{
    _thread = new thread(&Service::runProcess, this);
    _thread->join();
}
