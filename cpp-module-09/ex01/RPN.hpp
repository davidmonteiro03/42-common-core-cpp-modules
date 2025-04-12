/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:55:30 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 10:15:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <stack>

typedef double number_t;

class RPN
{
public:
	static void execute(const std::string &);

private:
	RPN(void);
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	static bool __checkValue(const std::string &);
	static number_t __calculate(const std::string &,
								const number_t &,
								const number_t &);
};
