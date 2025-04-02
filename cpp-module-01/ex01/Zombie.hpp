/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 07:48:22 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 10:23:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
public:
	Zombie(void);
	Zombie(const std::string &);
	Zombie(const Zombie &);
	Zombie &operator=(const Zombie &);
	~Zombie();

	const std::string &getName(void) const;
	void setName(const std::string &);

	void announce(void);

private:
	std::string __name;
};

Zombie *zombieHorde(int, std::string);
