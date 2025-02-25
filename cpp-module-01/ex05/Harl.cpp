/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:53:26 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 22:27:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl() {}

void Harl::debug(void) { std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"; }

void Harl::info(void) { std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"; }

void Harl::warning(void) { std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."; }

void Harl::error(void) { std::cout << "This is unacceptable! I want to speak to the manager now."; }

void Harl::complain(std::string level)
{
	t_func funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
	{
		std::cout << std::endl;
		(this->*funcs[i])();
		std::cout << std::endl
				  << std::endl;
	}
}
