/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:25:03 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 21:54:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(std::string);
	Zombie(void);
	~Zombie();
	void announce(void);
};

Zombie *newZombie(std::string);
void randomChump(std::string);
