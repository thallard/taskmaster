/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:56:16 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/10 01:04:56 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

void interpret_command(std::vector<std::string> tokens) {
    e_command_type type = getCommandType(tokens[0]);

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
    std::string command;
    std::vector<std::string> tokens;

    while (1) {
        std::cout << "\033[32;1m> \033[0m";
        getline(std::cin, command);
        if (!std::regex_match(command, std::regex("^[a-zA-Z_\\s]*$")))
            DEFAULT();
        else if (command != "")
            interpret_command(split(command, ' '));
    }
    return (0);
}