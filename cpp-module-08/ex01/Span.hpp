/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:31:53 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 10:24:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
public:
	Span(void);
	Span(const unsigned int &);
	Span(const Span &);
	Span &operator=(const Span &);
	~Span();

	void addNumber(const int &);

	int shortestSpan(void) const;
	int longestSpan(void) const;

	void addNumberRange(std::vector<int>::iterator,
						std::vector<int>::iterator);

	class SpanIsFullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class SpanTooSmallException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	std::vector<int> __data;
	unsigned int __maxSize;
};
