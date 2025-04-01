/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 17:34:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		const std::string tmp(argv[i]);
		for (std::size_t i = 0; i < tmp.size(); i++)
			std::cout << static_cast<char>(std::toupper(tmp[i]));
	}
	std::cout << std::endl;
	return 0;
}
