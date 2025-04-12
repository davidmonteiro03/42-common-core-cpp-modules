/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 09:55:30 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 09:58:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <stack>

class RPN
{
public:
	static void execute(const std::string &);

private:
	RPN(void);
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	static double __calculate(const std::string &,
							  const double &,
							  const double &);
};
