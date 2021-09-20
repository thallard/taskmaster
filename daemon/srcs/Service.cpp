//
// Created by Thomas Hallard-clot on 9/17/21.
//

#include "Service.hpp"


// Default constructor
Service::Service()
{

}

// Constructor per copy
Service::Service(Service const & ref)
{
    *this = ref;
}

//
Service &Service::operator=(const Service &ref)
{

    return *this;
}