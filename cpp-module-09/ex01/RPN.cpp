/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:57:20 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 10:00:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &) { return *this; }

RPN::~RPN() {}

double RPN::__calculate(const std::string &op,
						const double &a,
						const double &b)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::exception();
		return a / b;
	}
	throw std::exception();
}

void RPN::execute(const std::string &expr)
{
	std::stringstream exprSs(expr);
	std::stack<double> mstack;
	while (!exprSs.eof())
	{
		std::string arg = "";
		exprSs >> arg;
		if (arg == "+" || arg == "-" || arg == "*" || arg == "/")
		{
			if (mstack.size() < 2)
				throw std::exception();
			double b = mstack.top();
			mstack.pop();
			double a = mstack.top();
			mstack.pop();
			mstack.push(RPN::__calculate(arg, a, b));
			continue;
		}
		std::stringstream argSs(arg);
		double value = std::numeric_limits<double>::quiet_NaN();
		argSs >> value;
		if (std::isnan(value))
			throw std::exception();
		mstack.push(value);
	}
	if (mstack.size() != 1)
		throw std::exception();
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << mstack.top() << std::endl;
}
