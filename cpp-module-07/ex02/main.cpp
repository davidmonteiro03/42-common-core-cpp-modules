// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/04/08 19:29:38 by dcaetano          #+#    #+#             */
// /*   Updated: 2025/04/08 19:55:43 by dcaetano         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/* #include "Array.hpp"
#include <iostream>
#include <sstream>

template <typename A, typename B>
std::ostream &operator<<(std::ostream &os, std::pair<A, B> &pair) { return os << "(" << pair.first << ", " << pair.second << ")"; }

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &array)
{
	os << "[";
	for (std::size_t i = 0; i < array.size(); i++)
	{
		if (i > 0)
			os << ", ";
		os << array[i];
	}
	return os << "]";
}

Array<int> generateIntArray(const unsigned int &n)
{
	Array<int> result(n);
	for (std::size_t i = 0; i < result.size(); i++)
		result[i] = i + 1;
	return result;
}

Array<std::string> generateStrArray(const unsigned int &n)
{
	Array<std::string> result(n);
	for (std::size_t i = 0; i < result.size(); i++)
	{
		std::stringstream tmp;
		tmp << i + 1;
		result[i] = tmp.str();
	}
	return result;
}

Array<std::pair<int, int> > generatePairArray(const unsigned int &n)
{
	Array<std::pair<int, int> > result(n);
	for (std::size_t i = 0; i < result.size(); i++)
		result[i] = std::make_pair<int, int>(i + 1, n + i + 1);
	return result;
}

int main(void)
{
	Array<int> aInt1 = generateIntArray(5), aInt2 = generateIntArray(10);

	std::cout << "aInt1: " << aInt1 << std::endl
			  << "aInt2: " << aInt2 << std::endl
			  << std::endl;

	std::swap(aInt1, aInt2);

	std::cout << "aInt1: " << aInt1 << std::endl
			  << "aInt2: " << aInt2 << std::endl
			  << std::endl;

	Array<std::string> aStr1 = generateStrArray(5), aStr2 = generateStrArray(10);

	std::cout << "aStr1: " << aStr1 << std::endl
			  << "aStr2: " << aStr2 << std::endl
			  << std::endl;

	std::swap(aStr1, aStr2);

	std::cout << "aStr1: " << aStr1 << std::endl
			  << "aStr2: " << aStr2 << std::endl
			  << std::endl;

	Array<std::pair<int, int> > aPair1 = generatePairArray(5), aPair2 = generatePairArray(10);

	std::cout << "aPair1: " << aPair1 << std::endl
			  << "aPair2: " << aPair2 << std::endl
			  << std::endl;

	std::swap(aPair1, aPair2);

	std::cout << "aPair1: " << aPair1 << std::endl
			  << "aPair2: " << aPair2 << std::endl
			  << std::endl;

	return 0;
} */
