/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:22:15 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/11 07:15:06 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

/**
 * @brief Trim whitespace on left side of a string
 * 
 * @param s Reference to trimmed string
 */
void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),[](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

/**
 * @brief Trim whitespace on right side of a string
 * 
 * @param s Reference to trimmed string
 */
void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

/**
 * @brief Trim whitespace on left and right side of a string
 * 
 * @param s Reference to trimmed string
 */
void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

/**
 * @brief Split and trim string
 * 
 * @param str input string
 * @param delim splitted char
 * @return std::vector<std::string> Splitted string 
 */
std::vector<std::string> split(const std::string &str, char delim)
{
    std::string substring;
    std::vector<std::string> res;
    std::stringstream ss(str);
    
    while (getline(ss, substring, delim)) {
        trim(substring);
        if (substring != "")
            res.push_back(substring);
    }
    return (res);
}

/**
 * @brief Get the Command Type object
 * 
 * @param command Command string ex: "help"
 * @return t_command_type Corresponding enum value
 */
t_command_type getCommandType(std::string command) {
    static std::unordered_map<std::string, e_command_type> const table = {
        { "help",       HELP    },
        { "add",        ADD     },
        { "exit",       EXIT    },
        { "open",       OPEN    },
        { "reload",     RELOAD  },
        { "restart",    RESTART },
        { "start",      START   },
        { "tail",       TAIL    },
        { "avail",      AVAIL   },
        { "fg",         FG      },
        { "pid",        PID     },
        { "remove",     REMOVE  },
        { "shutdown",   SHUTDOWN},
        { "status",     STATUS  },
        { "update",     UPDATE  },
        { "clear",      CLEAR   },
        { "maintail",   MAINTAIL},
        { "quit",       QUIT    },
        { "reread",     REREAD  },
        { "signal",     SIGNAL  },
        { "stop",       STOP    },
        { "version",    VERSION }
    };
    
    auto it = table.find(command);
    if (it != table.end())
        return it->second;
    return (HELP);
}

/**
 * @brief Get the File Content object
 * 
 * @param path 
 * @return std::string 
 * @throw std::io_base::failure If file can't be open
 */
std::string getFileContent(std::string path) {
    std::ifstream file(path);
    
    if (!file.is_open())
        throw std::exception();
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return (str);
}

/**
 * @brief Remove unquoted space
 * 
 * @param str 
 */
void remove_unquoted_spaces(std::string &str) {
    bool end, in_quote;
    int i;

    end = false;
    while (!end) {
        i = 0;
        end = true;
        in_quote = false;
        while (str[i]) {
            if (str[i] == '\"')
                in_quote = !in_quote;
            else if (std::isspace(str[i]) && !in_quote) {
                str.erase(str.begin() + i);
                end = false;
                break;
            }
            i++;
        }
    }
}