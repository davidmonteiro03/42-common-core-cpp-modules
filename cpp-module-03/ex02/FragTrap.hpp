/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:01:44 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:07:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string &);
	FragTrap(const FragTrap &);
	FragTrap &operator=(const FragTrap &);
	~FragTrap();

	void highFivesGuys(void);

private:
	static const unsigned int __MAX_HIT_POINTS = 100;
	static const unsigned int __MAX_ENERGY_POINTS = 100;
	static const unsigned int __MAX_ATTACK_DAMAGE = 30;
};
