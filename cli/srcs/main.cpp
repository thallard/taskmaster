/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:56:16 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/09 23:17:48 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "global.hpp"

int main(int ac, const char **av) {
    (void)ac;
    (void)av;
    while (1) {
        string command;
        cout << ">";
        getline(cin, command);
        cout << command;
    }
    
    return (0);
}