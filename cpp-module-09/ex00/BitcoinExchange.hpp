/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:42:05 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 09:23:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <ctime>
#include <map>
#include <limits>
#include <cmath>
#include <exception>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
	~BitcoinExchange();

	void readCSVFile(void);
	void searchInputInDatabase(const std::string &) const;

private:
	std::map<std::string, float> __database;

	static long long int __getMonthDays(const long long int &,
										const long long int &);
	static bool __isValidDate(const long long int &,
							  const long long int &,
							  const long long int &);
	static std::tm __dmytotm(const long long int &,
							 const long long int &,
							 const long long int &);
	static std::string __tmtostr(const std::tm &);
	static std::tm __strtotm(const std::string &);
	static std::pair<std::string, float> __checkLine(const std::string &);

	class NotAPositiveNumberException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class TooLargeANumberException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class CouldNotOpenFileException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class DatabaseErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class InputFileWrongHeaderException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class DateIsTooOldException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
