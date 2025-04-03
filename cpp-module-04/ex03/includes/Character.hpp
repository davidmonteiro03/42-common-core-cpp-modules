/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:31:11 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 11:39:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Character : public ICharacter
{
public:
	Character(void);
	Character(const std::string &);
	Character(const Character &);
	Character &operator=(const Character &);
	~Character();

	const std::string &getName(void) const;

	void equip(AMateria *);
	void unequip(int);
	void use(int, ICharacter &);

private:
	static const std::size_t __MAX_SLOTS = 4;
	std::string __name;
	AMateria *__inventory[__MAX_SLOTS];
};
