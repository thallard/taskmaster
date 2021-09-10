/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:22:15 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/10 01:01:12 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

void ltrim(std::string &s) { s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); })); }
void rtrim(std::string &s) { s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end()); }
void trim(std::string &s) { ltrim(s); rtrim(s); }

constexpr unsigned int str2int(const char* str, int h = 0) { return (!str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h]); }

std::vector<std::string> split(const std::string &chaine, char delim)
{
    std::string substring;
    std::vector<std::string> res;
    std::stringstream ss(chaine);
    
    while (getline(ss, substring, delim)) {
        trim(substring);
        if (substring != "")
            res.push_back(substring);
    }
    return (res);
}

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
