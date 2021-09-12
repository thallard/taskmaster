//
// Created by Guillaume on 11/09/2021.
//

#include "JsonReader.hpp"

/**
 * @brief Extract json object from file
 * @param path
 * @return json object
 */
json::jobject JsonReader::parseFile(std::string path) {
    std::string content;
    try { content = getFileContent(path); }
    catch (const std::exception &e) { throw new FileNotExistException(); }
    return (parseString(content));
}

/**
 * @brief Extract json object from string
 * @param json_str
 * @return json object
 */
json::jobject JsonReader::parseString(std::string json_str) {
    return (json::jobject::parse(json_str));
}

/**
 * @brief Serialize a json object
 * @param json_object
 * @return corresponding string
 */
std::string JsonReader::stringify(json::jobject json_object) {
    return ((std::string)json_object);
}

// Exception class
const char* FileNotExistException::what() const throw() { return ("JsonReader Error: File not found or Operation not permitted"); }