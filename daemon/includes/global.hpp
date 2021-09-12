/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:19:36 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/09 23:20:07 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
// TODO Faire du c++ et pas du c <3

#include <iostream>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>

#ifdef _WIN32
#include <ws2tcpip.h>
#endif

#include "TunnelTCP.hpp"


//------------
// DEFINES
//------------
#define TUNNEL_PORT 4
#define BUFFER_SIZE 4096
#define ERR_FATAL "Fatal error"


#endif