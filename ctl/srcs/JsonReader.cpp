/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JsonReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 04:24:36 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/11 07:36:59 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "JsonReader.hpp"

JsonObject JsonReader::fileParser(std::string path) {
    std::string content;

    try { content = getFileContent(path); }
    catch (std::exception e) { throw new FileNotExistException(); }
    return (JsonReader::stringParser(content));
}

JsonObject JsonReader::stringParser(std::string json_str) {
    JsonObject<std::map<std::string, JsonObject>> root;

    
    std::cout << "JsonReader content = " << json_str << std::endl;
    tokenize(json_str);
    return ;
}

std::vector<std::string> JsonReader::tokenize(std::string json_str) {
    std::vector<std::string> result;
    
    remove_unquoted_spaces(json_str);
    std::cout << json_str << std::endl;
    for (auto i = json_str.begin(); i != json_str.end(); i++) {
        if (*i == '{')
            std::cout << "create map" << std::endl;
        else if (*i == '}')
            std::cout << "leave map" << std::endl;
        else if (*i == '[')
            std::cout << "create vector" << std::endl;
        else if (*i == ']')
            std::cout << "leave vector" << std::endl;
    }
    return (result);
}

const char* FileNotExistException::what() const throw() { return ("JsonReader Error: File not found"); }
