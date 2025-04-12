/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:42:00 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 09:28:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : __database(copy.__database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->__database = other.__database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

long long int BitcoinExchange::__getMonthDays(const long long int &month,
											  const long long int &year)
{
	if (month < 1 || month > 12 || year <= 0)
		return -1;
	if (month == 2)
		return 28 + (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	return 30 + ((month <= 7 && month % 2 == 1) || (month > 7 && month % 2 == 0));
}

bool BitcoinExchange::__isValidDate(const long long int &day,
									const long long int &month,
									const long long int &year)
{
	if (year <= 0 || month < 1 || month > 12 || day < 1)
		return false;
	return day <= BitcoinExchange::__getMonthDays(month, year);
}

std::tm BitcoinExchange::__dmytotm(const long long int &day,
								   const long long int &month,
								   const long long int &year)
{
	std::tm date;
	std::memset(&date, 0, sizeof(date));
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	std::mktime(&date);
	return date;
}

std::string BitcoinExchange::__tmtostr(const std::tm &date)
{
	char dateBuf[BUFSIZ];
	std::memset(dateBuf, 0, sizeof(dateBuf));
	std::strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", &date);
	return std::string(dateBuf);
}

std::tm BitcoinExchange::__strtotm(const std::string &str)
{
	std::tm date;
	std::memset(&date, 0, sizeof(date));
	strptime(str.c_str(), "%Y-%m-%d", &date);
	return date;
}

std::pair<std::string, float> BitcoinExchange::__checkLine(const std::string &line)
{
	if (line.empty())
		return std::pair<std::string, float>();
	std::stringstream lineSs(line);
	std::string dateStr = "", sepStr = "", valueStr = "";
	lineSs >> dateStr >> sepStr >> valueStr;
	if (dateStr.empty() || sepStr.empty() || valueStr.empty() || sepStr != "|")
		throw std::logic_error("bad input => " + line);
	std::stringstream dateSs(dateStr), valueSs(valueStr);
	std::string yearStr = "", monthStr = "", dayStr = "";
	float value = 0.f;
	std::getline(dateSs, yearStr, '-');
	std::getline(dateSs, monthStr, '-');
	std::getline(dateSs, dayStr);
	valueSs >> value;
	if (yearStr.empty() || monthStr.empty() || dayStr.empty())
		throw std::logic_error("bad input => " + line);
	std::stringstream yearSs(yearStr), monthSs(monthStr), daySs(dayStr);
	long long int year = 0, month = 0, day = 0;
	yearSs >> year;
	monthSs >> month;
	daySs >> day;
	if (BitcoinExchange::__isValidDate(day, month, year) == false)
		throw std::logic_error("bad input => " + line);
	if (value <= 0)
		throw BitcoinExchange::NotAPositiveNumberException();
	if (value >= 1000)
		throw BitcoinExchange::TooLargeANumberException();
	std::tm date = BitcoinExchange::__dmytotm(day, month, year);
	std::string dateString = BitcoinExchange::__tmtostr(date);
	return std::pair<std::string, float>(dateString, value);
}

void BitcoinExchange::readCSVFile(void)
{
	const std::string databaseFilename = "data.csv";
	std::ifstream databaseReadFile(databaseFilename.c_str());
	if (databaseReadFile.fail())
		throw BitcoinExchange::CouldNotOpenFileException();
	const std::string validColumns[] = {"date", "exchange_rate"};
	const std::size_t lenColumns = sizeof(validColumns) / sizeof(std::string);
	for (std::size_t i = 0; i < lenColumns; i++)
	{
		std::string tmp = "";
		if (i < lenColumns - 1)
			std::getline(databaseReadFile, tmp, ',');
		else
			std::getline(databaseReadFile, tmp);
		if (tmp != validColumns[i])
			throw BitcoinExchange::DatabaseErrorException();
	}
	while (!databaseReadFile.eof())
	{
		std::string dateStr = "", valueStr = "";
		std::getline(databaseReadFile, dateStr, ',');
		std::getline(databaseReadFile, valueStr);
		if (dateStr.empty() || valueStr.empty())
			continue;
		std::stringstream dateSs(dateStr), valueSs(valueStr);
		std::string yearStr = "", monthStr = "", dayStr = "";
		float value = 0.f;
		std::getline(dateSs, yearStr, '-');
		std::getline(dateSs, monthStr, '-');
		std::getline(dateSs, dayStr);
		valueSs >> value;
		if (yearStr.empty() || monthStr.empty() || dayStr.empty())
			continue;
		std::stringstream yearSs(yearStr), monthSs(monthStr), daySs(dayStr);
		long long int year = 0, month = 0, day = 0;
		yearSs >> year;
		monthSs >> month;
		daySs >> day;
		if (BitcoinExchange::__isValidDate(day, month, year) == false)
			continue;
		std::tm date = BitcoinExchange::__dmytotm(day, month, year);
		std::string dateString = BitcoinExchange::__tmtostr(date);
		this->__database[dateString] = value;
	}
}

void BitcoinExchange::searchInputInDatabase(const std::string &filename) const
{
	std::ifstream inputReadFile(filename.c_str());
	if (inputReadFile.fail())
		throw BitcoinExchange::CouldNotOpenFileException();
	const std::string validColumns[] = {"date", "value"};
	const std::size_t lenColumns = sizeof(validColumns) / sizeof(std::string);
	while (!inputReadFile.eof())
	{
		std::string line = "";
		std::getline(inputReadFile, line);
		std::stringstream lineSs(line);
		for (std::size_t i = 0; i < lenColumns; i++)
		{
			std::string tmpColumn = "";
			lineSs >> tmpColumn;
			if (tmpColumn != validColumns[i])
				throw BitcoinExchange::InputFileWrongHeaderException();
			if (i < lenColumns - 1)
			{
				std::string tmpSep = "";
				lineSs >> tmpSep;
				if (tmpSep != "|")
					throw BitcoinExchange::InputFileWrongHeaderException();
			}
		}
		break;
	}
	while (!inputReadFile.eof())
	{
		std::string line = "";
		std::getline(inputReadFile, line);
		if (line.empty())
			continue;
		try
		{
			std::pair<std::string, float> parsed = BitcoinExchange::__checkLine(line);
			std::tm date = BitcoinExchange::__strtotm(parsed.first);
			float findRate = std::numeric_limits<float>::quiet_NaN();
			for (std::size_t i = 0; i < this->__database.size(); i++)
			{
				std::string str = BitcoinExchange::__tmtostr(date);
				std::map<std::string, float>::const_iterator findExchange = this->__database.find(str);
				if (findExchange != this->__database.end())
				{
					findRate = findExchange->second;
					break;
				}
				date.tm_mday--;
				std::mktime(&date);
			}
			if (std::isnan(findRate))
				throw BitcoinExchange::DateIsTooOldException();
			std::cout.precision(std::numeric_limits<float>::digits10);
			std::cout << parsed.first << " => " << parsed.second << " = " << parsed.second * findRate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}
	}
}

const char *BitcoinExchange::NotAPositiveNumberException::what() const throw() { return "not a positive number."; }

const char *BitcoinExchange::TooLargeANumberException::what() const throw() { return "too large a number."; }

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw() { return "could not open file."; }

const char *BitcoinExchange::DatabaseErrorException::what() const throw() { return "database error."; }

const char *BitcoinExchange::InputFileWrongHeaderException::what() const throw() { return "input file wrong header."; }

const char *BitcoinExchange::DateIsTooOldException::what() const throw() { return "date is too old."; }
