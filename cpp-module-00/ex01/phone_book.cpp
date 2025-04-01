/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 18:30:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phone_book.hpp"

int main(void)
{
	PhoneBook book;
	while (!std::cin.eof())
	{
		std::string cmd = "";
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (cmd.empty())
			continue;
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}
