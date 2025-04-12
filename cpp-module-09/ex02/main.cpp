/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/12 14:30:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <vector>

static bool checkValue(const std::string &str)
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

template <typename A, typename B>
std::ostream &operator<<(std::ostream &os,
						 const std::pair<A, B> &pair) { return os << "(" << pair.first << ", " << pair.second << ")"; }

template <typename T>
std::ostream &operator<<(std::ostream &os,
						 const std::vector<T> &vector)
{
	for (typename std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (it != vector.begin())
			os << " ";
		os << *it;
	}
	return os;
}

static std::vector<int> argsListToVector(char **argv,
										 const int &size)
{
	std::vector<int> vector;
	for (int i = 0; i < size; i++)
	{
		if (checkValue(std::string(argv[i])) == false)
			throw std::exception();
		vector.push_back(std::atoi(argv[i]));
	}
	return vector;
}

static std::vector<std::pair<int, int> > sortPairs(const std::vector<int> &vector)
{
	std::vector<std::pair<int, int> > pairs;
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		int ___ = *it++;
		if (it == vector.end())
			break;
		pairs.push_back(std::pair<int, int>(___, *it));
	}
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first < it->second)
			std::swap(it->first, it->second);
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it + 1 != pairs.end();)
	{
		if (it->first > (it + 1)->first)
		{
			std::swap(*it, *(it + 1));
			it = pairs.begin();
		}
		else
			it++;
	}
	return pairs;
}

static std::vector<int> pairsLeftPart(const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> vector;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		vector.push_back(it->first);
	return vector;
}

static std::vector<int> pairsRightPart(const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> vector;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		vector.push_back(it->second);
	return vector;
}

static void smartInsert(std::vector<int> &vector,
						const int &newElement)
{
	std::vector<int>::iterator it;
	for (it = vector.begin(); it != vector.end() && *it < newElement; it++)
		;
	if (it == vector.end())
		return;
	vector.insert(it, newElement);
}

int main(int argc, char **argv)
{
	try
	{
		std::vector<int> vector = argsListToVector(argv + 1, argc - 1);
		std::vector<std::pair<int, int> > pairs = sortPairs(vector);
		std::vector<int> minorElements = pairsRightPart(pairs);
		std::vector<int> majorElements = pairsLeftPart(pairs);
		std::vector<int> result(majorElements);

		for (std::vector<int>::iterator it = minorElements.begin(); it != minorElements.end(); it++)
			smartInsert(result, *it);

		std::cout << vector << std::endl;
		std::cout << "--------------------------" << std::endl;
		std::cout << result << std::endl;
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
