/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:29:09 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 21:54:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::~Zombie() { std::cout << this->_name << " is death." << std::endl; }

void Zombie::announce(void) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie::Zombie(std::string name) : _name(name) { announce(); }
