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
    int sockfd;
    sockaddr_in addr;

    addr.sin_family = AF_INET; // Adress ip only
    addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    addr.sin_port = htons(TUNNEL_PORT); // Defined in global.h

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) // Create socket
        fatal(ERR_FATAL);
    if ((bind(sockfd, (sockaddr*)&addr, sizeof(addr))) < 0) // Bind socket to address + port
        fatal(ERR_FATAL);
    if ((listen(sockfd, 0)) < 0) // Start communication
        fatal(ERR_FATAL);
    std::cout << "Communication open :)" << std::endl;

    // std::string command;
    // std::vector<std::string> tokens;

    // while (1) {
    //     std::cout << "\033[32;1m> \033[0m";
    //     getline(std::cin, command);
    //     if (!std::regex_match(command, std::regex("^[a-zA-Z_\\s]*$")))
    //         DEFAULT();
    //     else if (command != "")
    //         interpret_command(split(command, ' '));
    // }

//    json::jobject object = JsonReader::parseFile("../../configs/commands.json");
//    std::cout << json::jobject::parse(object.get("help")).get("description") << std::endl;
//    std::cout << JsonReader::stringify(object) << std::endl;

    return (0);
}