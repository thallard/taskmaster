//
// Created by Thomas Hallard-clot on 9/20/21.
//

#include "ServiceManager.hpp"

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
    _thread = new std::thread(&Service::runProcess, *_service);
    sleep(10);
    _thread->join();
    std::cout << "kill ServiceManager thread\n";
}

// Return the Service
Service const &ServiceManager::getService() const
{
    return *_service;
}

// Return name of the specific Service
std::string const &ServiceManager::getServiceName() const
{
    return _service->getName();
}

// Set the Service
void ServiceManager::setService(Service *service)
{
    _service = service;
}

