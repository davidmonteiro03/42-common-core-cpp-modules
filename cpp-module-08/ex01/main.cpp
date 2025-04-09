/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 10:57:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}

// #include "Span.hpp"
// #include <iostream>

// static void addNumbersOneByOne(Span &sp, const int *values, const std::size_t &len)
// {
// 	if (values == NULL || len == 0)
// 		return;
// 	std::cout << ">>>> adding numbers 1 by 1" << std::endl;
// 	for (std::size_t i = 0; i < len; i++)
// 	{
// 		try
// 		{
// 			sp.addNumber(values[i]);
// 			std::cout << values[i] << " added successfully." << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << "Exception: " << e.what() << std::endl;
// 			break;
// 		}
// 	}
// 	std::cout << std::endl;
// }

// static void addNumbersRange(Span &sp, const int *values, const std::size_t &len)
// {
// 	if (values == NULL || len == 0)
// 		return;
// 	std::cout << ">>>> adding numbers range..." << std::endl;
// 	std::vector<int> range(len);
// 	for (std::size_t i = 0; i < len; i++)
// 		range[i] = values[i];
// 	sp.addNumberRange(range.begin(), range.end());
// 	std::cout << std::endl;
// }

// static void showShortestSpan(Span &sp)
// {
// 	std::cout << ">>>> show shortest span" << std::endl;
// 	try
// 	{
// 		const int shortestSpan = sp.shortestSpan();
// 		std::cout << "Shortest span: " << shortestSpan << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// }

// static void showLongestSpan(Span &sp)
// {
// 	std::cout << ">>>> show longest span" << std::endl;
// 	try
// 	{
// 		const int longestSpan = sp.longestSpan();
// 		std::cout << "Longest span: " << longestSpan << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// }

// int main()
// {
// 	std::cout << "========= Constructors and Destructors =========" << std::endl;
// 	{
// 		static const int values[] = {10, 20, 30, 40, 50};
// 		static const std::size_t N = sizeof(values) / sizeof(int);

// 		Span empty;
// 		Span span(N);
// 		Span emptyCopy(empty);
// 		Span spanCopy(span);

// 		std::cout << "--------- empty ---------" << std::endl;
// 		addNumbersOneByOne(empty, values, N);

// 		std::cout << "--------- span ---------" << std::endl;
// 		addNumbersOneByOne(span, values, N);

// 		std::cout << "--------- empty ---------" << std::endl;
// 		showShortestSpan(empty);
// 		showLongestSpan(empty);

// 		std::cout << "--------- span ---------" << std::endl;
// 		showShortestSpan(span);
// 		showLongestSpan(span);

// 		std::cout << ">>>> swapping..." << std::endl;
// 		std::swap(empty, span);
// 		std::cout << std::endl;

// 		std::cout << "--------- empty ---------" << std::endl;
// 		showShortestSpan(empty);
// 		showLongestSpan(empty);

// 		std::cout << "--------- span ---------" << std::endl;
// 		showShortestSpan(span);
// 		showLongestSpan(span);
// 	}

// 	std::cout << "========= Span 1 =========" << std::endl;
// 	{
// 		static const int values[] = {10, 20, 30, 40, 50};
// 		static const std::size_t N = sizeof(values) / sizeof(int);

// 		Span span(N);

// 		showShortestSpan(span);
// 		showLongestSpan(span);
// 		addNumbersOneByOne(span, values, N);
// 		showShortestSpan(span);
// 		showLongestSpan(span);
// 	}

// 	std::cout << "========= Span 2 =========" << std::endl;
// 	{
// 		static const int part1[] = {10, 20, 30};
// 		static const std::size_t part1N = sizeof(part1) / sizeof(int);

// 		static const int part2[] = {11, 31};
// 		static const std::size_t part2N = sizeof(part2) / sizeof(int);

// 		Span span(part1N + part2N);

// 		showShortestSpan(span);
// 		showLongestSpan(span);
// 		addNumbersOneByOne(span, part1, part1N);
// 		showShortestSpan(span);
// 		showLongestSpan(span);
// 		addNumbersRange(span, part2, part2N);
// 		showShortestSpan(span);
// 		showLongestSpan(span);
// 	}

// 	return 0;
// }
