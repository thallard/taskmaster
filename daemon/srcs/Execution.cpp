//
// Created by Thomas Hallard-clot on 9/17/21.
//

//TODO: Need to rename the class

#include "Execution.hpp"
Execution::Execution() {

}

Execution::~Execution() {

}

// Add a new service in the list
bool Execution::addService(Service *service) {
    if (service)
        _services.push_back(service);
    else
        return false;
    return true;
}

// Search for a service and delete it
bool Execution::delService(std::string const & name) {
    for (auto begin = _services.begin(); begin != _services.end(); begin++)
    {
        if ((*begin)->getName() == name)
        {
            _services.erase(begin);
            delete *begin;
            return true;
        }
    }
    return false;
}

// Return number of services stored
int Execution::getServicesCount()
{
    return _services.size();
}