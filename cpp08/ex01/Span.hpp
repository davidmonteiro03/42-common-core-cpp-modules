/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:43:16 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 09:37:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
private:
	unsigned int _length;
	std::vector<int> _storage;

public:
	Span();
	Span(unsigned int);
	Span(const Span &);
	Span &operator=(const Span &);
	virtual ~Span();
	void addNumber(int);
	int shortestSpan(void);
	int longestSpan(void) const;
	void addNumberRange(std::vector<int>::iterator, std::vector<int>::iterator);
	class VectorIsFullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class TooFewElementsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
