/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 16:09:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void checkConstructorsAndAssignments(void)
{
	std::cout << "===== DEFAULT CONSTRUCTOR =====" << std::endl;
	try
	{
		Bureaucrat b;
		std::cout << "Bureaucrat: " << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== CUSTOM CONSTRUCTOR =====" << std::endl;
	try
	{
		Bureaucrat custom("custom", 42);
		std::cout << "Bureaucrat: " << custom << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== COPY CONSTRUCTOR =====" << std::endl;
	try
	{
		Bureaucrat custom("custom", 42);
		Bureaucrat copy(custom);
		std::cout << "Bureaucrat: " << custom << std::endl;
		std::cout << "Bureaucrat: " << copy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== ASSIGNMENT OPERATOR =====" << std::endl;
	try
	{
		Bureaucrat custom("custom", 42);
		Bureaucrat other("other", 50);
		std::cout << "Bureaucrat: " << custom << std::endl;
		std::cout << "Bureaucrat: " << other << std::endl;
		other = custom;
		std::cout << "Bureaucrat: " << custom << std::endl;
		std::cout << "Bureaucrat: " << other << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void checkExceptions(void)
{
	std::cout << "===== GRADE TOO LOW EXCEPTION =====" << std::endl;
	try
	{
		Bureaucrat gradeTooLow("grade too low", 151);
		std::cout << "Bureaucrat: " << gradeTooLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== GRADE TOO HIGH EXCEPTION =====" << std::endl;
	try
	{
		Bureaucrat gradeTooHigh("grade too high", 0);
		std::cout << "Bureaucrat: " << gradeTooHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void checkIncrementAndDecrement(void)
{
	std::cout << "===== DECREMENT GRADE =====" << std::endl;
	try
	{
		Bureaucrat ___("___", 1);
		std::cout << "Bureaucrat: " << ___ << std::endl;
		while (true)
		{
			try
			{
				___.decrementGrade();
				std::cout << "Bureaucrat: " << ___ << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
				break;
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== INCREMENT GRADE =====" << std::endl;
	try
	{
		Bureaucrat ___("___", 150);
		std::cout << "Bureaucrat: " << ___ << std::endl;
		while (true)
		{
			try
			{
				___.incrementGrade();
				std::cout << "Bureaucrat: " << ___ << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
				break;
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	checkConstructorsAndAssignments();
	checkExceptions();
	checkIncrementAndDecrement();
	return 0;
}
