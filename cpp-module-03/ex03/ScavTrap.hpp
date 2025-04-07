/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:01:44 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:40:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const std::string &);
	ScavTrap(const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &);
	~ScavTrap();

	void attack(const std::string &);
	void guardGate(void);

protected:
	static const unsigned int _MAX_HIT_POINTS;
	static const unsigned int _MAX_ENERGY_POINTS;
	static const unsigned int _MAX_ATTACK_DAMAGE;
};
