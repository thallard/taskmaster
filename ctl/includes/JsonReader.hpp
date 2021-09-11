/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JsonReader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 04:24:19 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/11 07:38:20 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_READER_HPP
#define JSON_READER_HPP

#include "global.hpp"

template<typename T>
class JsonObject;

class JsonReader {
    public:
        // Methods
        static JsonObject<std::map<std::string, JsonObject>> fileParser(std::string);
        static JsonObject<std::map<std::string, JsonObject>> stringParser(std::string);

    // Properties
    private:
        JsonReader() {};
        static std::vector<std::string> tokenize(std::string);
};

// Exceptions
class FileNotExistException : public std::exception { virtual const char* what() const throw(); };

#endif