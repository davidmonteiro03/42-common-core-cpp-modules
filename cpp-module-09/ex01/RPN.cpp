/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:57:20 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 10:15:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &) { return *this; }

RPN::~RPN() {}

bool RPN::__checkValue(const std::string &str)
{
	if (str.empty())
		return false;
	std::size_t i = 0;
	while (i < str.size() && std::isspace(str[i]))
		i++;
	bool hasDigits = i < str.size() && std::isdigit(str[i]);
	while (i < str.size() && std::isdigit(str[i]))
		i++;
	while (i < str.size() && std::isspace(str[i]))
		i++;
	return i == str.size() && hasDigits == true;
}

number_t RPN::__calculate(const std::string &op,
						  const number_t &a,
						  const number_t &b)
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
	std::stack<number_t> mstack;
	while (!exprSs.eof())
	{
		std::string arg = "";
		exprSs >> arg;
		if (arg == "+" || arg == "-" || arg == "*" || arg == "/")
		{
			if (mstack.size() < 2)
				throw std::exception();
			number_t b = mstack.top();
			mstack.pop();
			number_t a = mstack.top();
			mstack.pop();
			mstack.push(RPN::__calculate(arg, a, b));
			continue;
		}
		if (RPN::__checkValue(arg) == false)
			throw std::exception();
		std::stringstream argSs(arg);
		number_t value = std::numeric_limits<number_t>::quiet_NaN();
		if (!(argSs >> value))
			throw std::exception();
		mstack.push(value);
	}
	if (mstack.size() != 1)
		throw std::exception();
	std::cout.precision(std::numeric_limits<number_t>::digits10);
	std::cout << mstack.top() << std::endl;
}
