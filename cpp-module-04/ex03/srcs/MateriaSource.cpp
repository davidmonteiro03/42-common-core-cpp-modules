/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:31:11 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 11:38:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/interface.hpp"

MateriaSource::MateriaSource(void) { std::memset(this->__materias, 0, sizeof(this->__materias)); }

MateriaSource::MateriaSource(const MateriaSource &copy) { std::memcpy(this->__materias, copy.__materias, sizeof(this->__materias)); }

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (std::size_t i = 0; i < MateriaSource::__MAX_SLOTS; i++)
			if (this->__materias[i] != NULL)
				delete this->__materias[i];
		std::memcpy(this->__materias, other.__materias, sizeof(this->__materias));
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (std::size_t i = 0; i < MateriaSource::__MAX_SLOTS; i++)
		if (this->__materias[i] != NULL)
			delete this->__materias[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return ;
	for (std::size_t i = 0; i < MateriaSource::__MAX_SLOTS; i++)
	{
		if (this->__materias[i] == NULL)
		{
			this->__materias[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (std::size_t i = 0; i < MateriaSource::__MAX_SLOTS; i++)
		if (this->__materias[i] != NULL && this->__materias[i]->getType() == type)
			return this->__materias[i]->clone();
	return NULL;
}
