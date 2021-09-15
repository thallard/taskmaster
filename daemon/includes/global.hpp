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

//------------
// DEFINES
//------------
#define TUNNEL_PORT 8081
#define BUFFER_SIZE 4096
#define ERR_FATAL "Fatal error"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
// TODO Faire du c++ et pas du c <3

#include <thread>
#include <vector>
#include <csignal>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#include "TunnelTCP.hpp"

#endif
