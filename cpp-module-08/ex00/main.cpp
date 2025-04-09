/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 09:30:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main(void)
{
	static const int insertValues[] = {10, 20, 30, 40, 50};
	static const int searchValues[] = {10, 20, 30, 40, 50};

	std::cout << "========= easyfind - vector =========" << std::endl;
	{
		std::vector<int> v;

		for (std::size_t i = 0; i < sizeof(insertValues) / sizeof(int); i++)
			v.push_back(insertValues[i]);

		for (std::size_t i = 0; i < sizeof(searchValues) / sizeof(int); i++)
		{
			std::vector<int>::iterator findElement = ::easyfind(v, searchValues[i]);
			if (findElement != v.end())
				std::cout << searchValues[i] << " found!" << std::endl;
			else
				std::cout << searchValues[i] << " not found." << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "========= easyfind - deque =========" << std::endl;
	{
		std::deque<int> d;

		for (std::size_t i = 0; i < sizeof(insertValues) / sizeof(int); i++)
			d.push_back(insertValues[i]);

		for (std::size_t i = 0; i < sizeof(searchValues) / sizeof(int); i++)
		{
			std::deque<int>::iterator findElement = ::easyfind(d, searchValues[i]);
			if (findElement != d.end())
				std::cout << searchValues[i] << " found!" << std::endl;
			else
				std::cout << searchValues[i] << " not found." << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "========= easyfind - list =========" << std::endl;
	{
		std::list<int> l;

		for (std::size_t i = 0; i < sizeof(insertValues) / sizeof(int); i++)
			l.push_back(insertValues[i]);

		for (std::size_t i = 0; i < sizeof(searchValues) / sizeof(int); i++)
		{
			std::list<int>::iterator findElement = ::easyfind(l, searchValues[i]);
			if (findElement != l.end())
				std::cout << searchValues[i] << " found!" << std::endl;
			else
				std::cout << searchValues[i] << " not found." << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
