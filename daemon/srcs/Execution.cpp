//
// Created by Thomas Hallard-clot on 9/17/21.
//

//TODO: Need to rename the class

#include "Execution.hpp"
Execution::Execution() {

}

Execution::~Execution() {

}

// Add a new ServiceManager in the list
bool Execution::addManager(ServiceManager *service) {
    if (service)
        _managers.push_back(service);
    else
        return false;
    return true;
}

// Search for a service and delete it
bool Execution::delManager(std::string const & name) {
    for (auto begin = _managers.begin(); begin != _managers.end(); begin++)
    {
        if ((*begin)->getService().getName() == name)
        {
            _managers.erase(begin);
            delete *begin;
            return true;
        }
    }
    return false;
}

// Return number of services stored
int Execution::getManagersCount()
{
    return _managers.size();
}