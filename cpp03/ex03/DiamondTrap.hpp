/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:50:42 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:14:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;

public:
	// Orthodox Canonical Form
	DiamondTrap(std::string);
	DiamondTrap(const DiamondTrap &);
	DiamondTrap &operator=(const DiamondTrap &);
	~DiamondTrap();

	// member functions
	void attack(const std::string &);
	void whoAmI();
};
