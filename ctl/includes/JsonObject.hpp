/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JsonObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 04:24:19 by gbaud             #+#    #+#             */
/*   Updated: 2021/09/11 07:37:29 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include "global.hpp"

template<typename T>
class JsonObject {
    JsonObject() {};
    ~JsonObject() {};

    std::string key;
    T value;
};

#endif