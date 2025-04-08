/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:33:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 16:45:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter
{
public:
	static void convert(const std::string &);

private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();

	static bool __isChar(const std::string &);
	static bool __isInt(const std::string &);
	static bool __isFloat(const std::string &);
	static bool __isDouble(const std::string &);

	static void __showChar(const char &);
	static void __showInt(const int &);
	static void __showFloat(const float &);
	static void __showDouble(const double &);
};
