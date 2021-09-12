//
// Created by Guillaume on 11/09/2021.
//

#ifndef TASKMASTER_CTL_JSONREADER_HPP
#define TASKMASTER_CTL_JSONREADER_HPP

#include "global.hpp"

class JsonReader {
public:
    static json::jobject parseFile(std::string path);
    static json::jobject parseString(std::string json_str);
    static std::string stringify(json::jobject object);
};

class FileNotExistException : public std::exception { virtual const char *what() const throw(); };

#endif //TASKMASTER_CTL_JSONREADER_HPP
