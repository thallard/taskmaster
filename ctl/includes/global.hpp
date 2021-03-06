/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:17:10 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/11 07:35:20 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

//------------
// DEFINES
//------------
#define TUNNEL_PORT 8081
#define BUFFER_SIZE 4096
#define ERR_FATAL "Fatal error"

//------------
// MACROS :
//------------
#define DEFAULT() std::cout << "type help <command>" << std::endl

#include <unordered_map>
#include <exception>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <thread>

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

//-----------
// LIBRARY (parsing) :
//-----------
#include "json.hpp"

//-----------
// CLASS :
//-----------
#include "JsonReader.hpp"
#include "TunnelTCP.hpp"

typedef enum e_command_type {
    HELP,
    ADD,
    EXIT,
    OPEN,
    RELOAD,
    RESTART,
    START,
    TAIL,
    AVAIL,
    FG,
    PID,
    REMOVE,
    SHUTDOWN,
    STATUS,
    UPDATE,
    CLEAR,
    MAINTAIL,
    QUIT,
    REREAD,
    SIGNAL,
    STOP,
    VERSION
} t_command_type;

//------------
// Globals
//------------

//------------
// utils.cpp
//------------
void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
std::vector<std::string> split(const std::string &chaine, char delim);
t_command_type getCommandType(std::string command);
std::string getFileContent(std::string path);
void remove_unquoted_spaces(std::string &str);

void fatal(std::string err);

#endif