/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:37:40 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:56:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &value) { std::cout << value << std::endl; }

void ft_change(int &value) { value = 42; }

void ft_change(std::string &value) { value = "42"; }

int main(void)
{
	int ints[] = {1, 2, 3, 4, 5};

	::iter(ints, sizeof(ints) / sizeof(int), print);
	::iter(ints, sizeof(ints) / sizeof(int), ft_change);
	::iter(ints, sizeof(ints) / sizeof(int), print);

	std::string strs[] = {"1", "2", "3", "4", "5"};

	::iter(strs, sizeof(strs) / sizeof(std::string), print);
	::iter(strs, sizeof(strs) / sizeof(std::string), ft_change);
	::iter(strs, sizeof(strs) / sizeof(std::string), print);

	return 0;
}
