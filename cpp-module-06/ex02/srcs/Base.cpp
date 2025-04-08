/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:54:52 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:31:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::Base(void) {}

Base::~Base() {}

Base *generate(void)
{
	unsigned int option = std::rand() % 4;
	switch (option)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	default:
		return NULL;
		break;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C pointer" << std::endl;
	else
		std::cout << "NULL pointer" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		return std::cout << "A reference" << std::endl, void(a);
	}
	catch (...)
	{
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		return std::cout << "B reference" << std::endl, void(b);
	}
	catch (...)
	{
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		return std::cout << "C reference" << std::endl, void(c);
	}
	catch (...)
	{
	}

	std::cout << "NULL reference" << std::endl;
}
