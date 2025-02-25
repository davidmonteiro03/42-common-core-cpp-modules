/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:26:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") { std::cout << this->_type << " created" << std::endl; }

WrongCat::~WrongCat() { std::cout << this->_type << " destroyed" << std::endl; }

void WrongCat::makeSound(void) const { std::cout << "Animal " << this->getType() << " said meooowwwww. It's not a cat." << std::endl; }
