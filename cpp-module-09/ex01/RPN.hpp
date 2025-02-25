/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:40:13 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 09:56:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <stack>
#include <cstdlib>

class RPN
{
private:
	std::stack<double> _stack;

public:
	RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();
	void execute(std::string);
	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
