/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:35:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 16:46:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::__isChar(const std::string &input)
{
	if (input.empty())
		return false;
	if (input.size() == 1 && !std::isdigit(input[0]))
		return true;
	std::size_t i = 0;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	bool hasChar = i < input.size() && !std::isdigit(input[i]);
	if (i < input.size() && !std::isdigit(input[i]))
		i++;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	return i == input.size() && hasChar == true;
}

bool ScalarConverter::__isInt(const std::string &input)
{
	if (input.empty())
		return false;
	std::size_t i = 0;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i < input.size() && (input[i] == '+' || input[i] == '-'))
		i++;
	bool hasDigits = i < input.size() && std::isdigit(input[i]);
	while (i < input.size() && std::isdigit(input[i]))
		i++;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	return i == input.size() && hasDigits == true;
}

bool ScalarConverter::__isFloat(const std::string &input)
{
	if (input.empty())
		return false;
	std::size_t i = 0;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i < input.size() && (input[i] == '+' || input[i] == '-'))
		i++;
	bool hasDigitsLeft = i < input.size() && std::isdigit(input[i]);
	while (i < input.size() && std::isdigit(input[i]))
		i++;
	bool hasPoint = i < input.size() && input[i] == '.';
	if (i < input.size() && input[i] == '.')
		i++;
	bool hasDigitsRight = i < input.size() && std::isdigit(input[i]);
	while (i < input.size() && std::isdigit(input[i]))
		i++;
	bool hasF = i < input.size() && input[i] == 'f';
	if (i < input.size() && input[i] == 'f')
		i++;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	return i == input.size() && (hasDigitsLeft == true || hasDigitsRight == true) && hasPoint == true && hasF == true;
}

bool ScalarConverter::__isDouble(const std::string &input)
{
	if (input.empty())
		return false;
	std::size_t i = 0;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i < input.size() && (input[i] == '+' || input[i] == '-'))
		i++;
	bool hasDigitsLeft = i < input.size() && std::isdigit(input[i]);
	while (i < input.size() && std::isdigit(input[i]))
		i++;
	bool hasPoint = i < input.size() && input[i] == '.';
	if (i < input.size() && input[i] == '.')
		i++;
	bool hasDigitsRight = i < input.size() && std::isdigit(input[i]);
	while (i < input.size() && std::isdigit(input[i]))
		i++;
	while (i < input.size() && std::isspace(input[i]))
		i++;
	return i == input.size() && (hasDigitsLeft == true || hasDigitsRight == true) && hasPoint == true;
}

void ScalarConverter::__showChar(const char &c)
{
	std::cout.precision(std::numeric_limits<double>::digits10);
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c);
	if (std::fmod(static_cast<float>(c), 1.0f) == 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c);
	if (std::fmod(static_cast<double>(c), 1.0) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::__showInt(const int &i)
{
	std::cout.precision(std::numeric_limits<double>::digits10);
	if (i < static_cast<int>(std::numeric_limits<char>::min()) ||
		i > static_cast<int>(std::numeric_limits<char>::max()))
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i);
	if (std::fmod(static_cast<float>(i), 1.0f) == 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i);
	if (std::fmod(static_cast<double>(i), 1.0) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::__showFloat(const float &f)
{
	std::cout.precision(std::numeric_limits<double>::digits10);
	if (f < static_cast<float>(std::numeric_limits<char>::min()) ||
		f > static_cast<float>(std::numeric_limits<char>::max()))
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (f < static_cast<float>(std::numeric_limits<int>::min()) ||
		f > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f;
	if (std::fmod(f, 1.0f) == 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f);
	if (std::fmod(static_cast<double>(f), 1.0) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::__showDouble(const double &d)
{
	std::cout.precision(std::numeric_limits<double>::digits10);
	if (d < static_cast<double>(std::numeric_limits<char>::min()) ||
		d > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
		d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d);
	if (std::fmod(static_cast<float>(d), 1.0f) == 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (std::fmod(d, 1.0) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	std::stringstream inputSs(input);
	if (ScalarConverter::__isChar(input))
	{
		char c = 0;
		if (input.size() == 1)
			c = input[0];
		else if (!(inputSs >> c))
			return std::cerr << "Convertion is impossible." << std::endl, void(0);
		return ScalarConverter::__showChar(c);
	}
	if (ScalarConverter::__isInt(input))
	{
		int i = 0;
		if (!(inputSs >> i))
			return std::cerr << "Convertion is impossible." << std::endl, void(0);
		return ScalarConverter::__showInt(i);
	}
	if (ScalarConverter::__isFloat(input))
	{
		float f = 0;
		if (!(inputSs >> f))
			return std::cerr << "Convertion is impossible." << std::endl, void(0);
		return ScalarConverter::__showFloat(f);
	}
	if (ScalarConverter::__isDouble(input))
	{
		double d = 0;
		if (!(inputSs >> d))
			return std::cerr << "Convertion is impossible." << std::endl, void(0);
		return ScalarConverter::__showDouble(d);
	}
}
