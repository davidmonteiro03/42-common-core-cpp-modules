/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 16:08:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void checkConstructorsAndAssignments(void)
{
	std::cout << "===== DEFAULT CONSTRUCTOR =====" << std::endl;
	try
	{
		Form f;
		std::cout << "Form: " << f << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== CUSTOM CONSTRUCTOR =====" << std::endl;
	try
	{
		Form custom("custom", 42, 42);
		std::cout << "Form: " << custom << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== COPY CONSTRUCTOR =====" << std::endl;
	try
	{
		Form custom("custom", 42, 42);
		Form copy(custom);
		std::cout << "Form: " << custom << std::endl;
		std::cout << "Form: " << copy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== ASSIGNMENT OPERATOR =====" << std::endl;
	try
	{
		Form custom("custom", 42, 42);
		Form other("other", 50, 50);
		std::cout << "Form: " << custom << std::endl;
		std::cout << "Form: " << other << std::endl;
		other = custom;
		std::cout << "Form: " << custom << std::endl;
		std::cout << "Form: " << other << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void checkExceptions(void)
{
	std::cout << "===== GRADE TO SIGN TOO LOW EXCEPTION =====" << std::endl;
	try
	{
		Form gradeToSignTooLow("grade to sign too low", 151, 1);
		std::cout << "Form: " << gradeToSignTooLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== GRADE TO SIGN TOO HIGH EXCEPTION =====" << std::endl;
	try
	{
		Form gradeToSignTooHigh("grade to sign too high", 0, 1);
		std::cout << "Form: " << gradeToSignTooHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== GRADE TO EXECUTE TOO LOW EXCEPTION =====" << std::endl;
	try
	{
		Form gradeToExecuteTooLow("grade to sign too low", 1, 151);
		std::cout << "Form: " << gradeToExecuteTooLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== GRADE TO EXECUTE TOO HIGH EXCEPTION =====" << std::endl;
	try
	{
		Form gradeToExecuteTooHigh("grade to sign too high", 1, 0);
		std::cout << "Form: " << gradeToExecuteTooHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void checkSigning(void)
{
	std::cout << "===== GOOD GRADE TO SIGN =====" << std::endl;
	{
		Bureaucrat ___b("___b", 42);
		Form ___f("___f", 42, 42);
		std::cout << "Bureaucrat: " << ___b << std::endl;
		std::cout << "Form: " << ___f << std::endl;
		___b.signForm(___f);
	}
	std::cout << std::endl;

	std::cout << "===== BAD GRADE TO SIGN =====" << std::endl;
	{
		Bureaucrat ___b("___b", 43);
		Form ___f("___f", 42, 42);
		std::cout << "Bureaucrat: " << ___b << std::endl;
		std::cout << "Form: " << ___f << std::endl;
		___b.signForm(___f);
	}
	std::cout << std::endl;

	std::cout << "===== BAD TO GOOD GRADE TO SIGN =====" << std::endl;
	{
		Bureaucrat ___b("___b", 5);
		Form ___f("___f", 1, 1);
		std::cout << "Bureaucrat: " << ___b << std::endl;
		std::cout << "Form: " << ___f << std::endl;
		std::cout << std::endl;
		while (true)
		{
			___b.signForm(___f);
			if (___f.getIsSigned() == true)
				break;
			___b.incrementGrade();
			std::cout << "Bureaucrat: " << ___b << std::endl;
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Form: " << ___f << std::endl;
	}
	std::cout << std::endl;

	std::cout << "===== GOOD TO BAD GRADE TO SIGN =====" << std::endl;
	{
		Bureaucrat ___b("___b", 1);
		Form ___f("___f", 5, 1);
		std::cout << "Bureaucrat: " << ___b << std::endl;
		std::cout << "Form: " << ___f << std::endl;
		std::cout << std::endl;
		while (___b.getGrade() <= ___f.getGradeToSign())
		{
			___b.decrementGrade();
			std::cout << "Bureaucrat: " << ___b << std::endl;
		}
		std::cout << std::endl;
		___b.signForm(___f);
		std::cout << std::endl;
		std::cout << "Form: " << ___f << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	checkConstructorsAndAssignments();
	checkExceptions();
	checkSigning();
	return 0;
}
