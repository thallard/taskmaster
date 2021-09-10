/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:17:10 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/10 01:02:38 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

//------------
// MACROS :
//------------
#define DEFAULT() std::cout << "type help <command>" << std::endl

//------------
// DEFINES
//------------
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
// utils.cpp
//------------
void ltrim(std::string &s);
void rtrim(std::string &s);
void trim(std::string &s);
constexpr unsigned int str2int(const char* str, int h);
std::vector<std::string> split(const std::string &chaine, char delim);
t_command_type getCommandType(std::string command);
