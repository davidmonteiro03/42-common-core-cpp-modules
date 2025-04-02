/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:03:26 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
public:
	HumanB(void);
	HumanB(const std::string &);
	HumanB(const HumanB &);
	HumanB &operator=(const HumanB &);
	~HumanB();

	void setWeapon(Weapon &);

	void attack(void) const;

private:
	Weapon *__weapon;
	std::string __name;
};
