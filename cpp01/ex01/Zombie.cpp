/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:29:09 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 21:56:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie() {}

void Zombie::announce(void) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::set_name(std::string name) { this->_name = name; }

Zombie::Zombie(std::string name) : _name(name) { announce(); }
