/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:32:32 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:52:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];

public:
	Character(std::string);
	Character(const Character &);
	Character &operator=(const Character &);
	~Character();
	std::string const &getName() const;
	void equip(AMateria *);
	void unequip(int);
	void use(int, ICharacter &);
};
