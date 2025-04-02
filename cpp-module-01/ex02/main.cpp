/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 08:42:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "memory address of string: " << &string << std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "value of string: " << string << std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;

	// stringREF = "HI THIS IS REF";

	// std::cout << "value of string: " << string << std::endl;
	// std::cout << "value pointed to by stringPTR: " << *stringPTR << std::endl;
	// std::cout << std::endl;

	// *stringPTR = "HI THIS IS PTR";

	// std::cout << "value of string: " << string << std::endl;
	// std::cout << "value pointed to by stringREF: " << stringREF << std::endl;
	// std::cout << std::endl;

	return 0;
}
