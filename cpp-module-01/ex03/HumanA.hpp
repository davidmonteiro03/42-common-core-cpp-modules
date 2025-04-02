/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:50:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
public:
	HumanA(Weapon &);
	HumanA(const std::string &, Weapon &);
	HumanA(const HumanA &);
	HumanA &operator=(const HumanA &);
	~HumanA();

	void attack(void) const;

private:
	Weapon &__weapon;
	std::string __name;
};
