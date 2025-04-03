/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:31:11 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 11:23:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/interface.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) : _type(copy._type) {}

AMateria &AMateria::operator=(const AMateria &) { return *this; }

AMateria::~AMateria() {}

const std::string &AMateria::getType(void) const { return this->_type; }

void AMateria::use(ICharacter &) {}
