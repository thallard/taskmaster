/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:56:16 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/11 05:08:22 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

/**
 * @brief Fatal error, exit after print error
 * 
 * @param err Error constant or string
 */
void fatal(std::string err) {
    std::cerr << err << std::endl;
    exit(1);
}

/**
 * @brief Interpret command and args, communicate with daemon if necessary
 * 
 * @param tokens Command + Args vector
 */
void interpret_command(std::vector<std::string> tokens) {
    // Get command corresponding type
    e_command_type type = getCommandType(tokens[0]);

    // Apply effect for each type
    switch (type) {
        case HELP:
            DEFAULT();
            break;
        
        default:
            std::cout << type << std::endl;
            break;
    }
}

int main() {
    TunnelTCP *tunnel;

    tunnel = new TunnelTCP();
    if (tunnel->init())
        fatal("=> TunnelTCP Error Exit");
    tunnel->start();

    while (1) {
        std::string cmd;

        std::cin >> cmd;
        std::cout << "Add data [" << cmd << "]" << std::endl;
        tunnel->addData(cmd);
    }

    return (0);
}