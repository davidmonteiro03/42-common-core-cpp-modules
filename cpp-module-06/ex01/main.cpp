/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:13:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Data &d) { return os << "===== Data <" << &d << "> =====" << std::endl
																	  << "age: " << d.age << std::endl
																	  << "name: " << d.name << std::endl; }

int main(void)
{
	Data *data = new Data;

	data->name = "David";
	data->age = 21;

	if (data != NULL)
		std::cout << *data << std::endl;
	else
		std::cout << "NULL PTR" << std::endl
				  << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "raw: " << raw << std::endl
			  << std::endl;

	Data *ptr = Serializer::deserialize(raw);

	std::cout << *ptr << std::endl;

	ptr->name = "42";
	ptr->age = 42;

	std::cout << *data << std::endl;

	if (data != NULL)
		delete data;

	uintptr_t nullRaw = Serializer::serialize(NULL);
	std::cout << "nullRaw: " << nullRaw << std::endl
			  << std::endl;

	Data *nullPtr = Serializer::deserialize(nullRaw);

	if (nullPtr != NULL)
		std::cout << *nullPtr << std::endl;
	else
		std::cout << "NULL PTR" << std::endl
				  << std::endl;

	return 0;
}
