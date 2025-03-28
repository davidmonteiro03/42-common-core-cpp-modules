/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:09:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 22:23:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void) { return this->_type; }

void Weapon::setType(std::string type) { this->_type = type; }
