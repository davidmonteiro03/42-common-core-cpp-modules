/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:24:19 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 11:07:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::Harl(const Harl &) {}

Harl &Harl::operator=(const Harl &) { return *this; }

Harl::~Harl() {}

void Harl::complain(std::string level)
{
	harl_message_t messages[4] = {(harl_message_t){.level = "DEBUG", .func = &Harl::debug},
								  (harl_message_t){.level = "INFO", .func = &Harl::info},
								  (harl_message_t){.level = "WARNING", .func = &Harl::warning},
								  (harl_message_t){.level = "ERROR", .func = &Harl::error}};
	std::size_t i;
	for (i = 0; i < 4; i++)
		if (level == messages[i].level)
			break;
	if (i < 0 || i > 3)
		return;
	(this->*messages[i].func)();
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
			  << "I really do!" << std::endl
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
			  << "I think I deserve to have some extra bacon for free." << std::endl
			  << "I've been coming for years, whereas you started working here just last month." << std::endl
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now." << std::endl
			  << std::endl;
}
