/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:34:58 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 10:58:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : __data(),
				   __maxSize(0) {}

Span::Span(const unsigned int &N) : __data(),
									__maxSize(N) {}

Span::Span(const Span &copy) : __data(copy.__data),
							   __maxSize(copy.__maxSize) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->__data = other.__data;
		this->__maxSize = other.__maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(const int &n)
{
	if (this->__data.size() == this->__maxSize)
		throw Span::SpanIsFullException();
	this->__data.push_back(n);
}

int Span::shortestSpan(void) const
{
	if (this->__data.size() < 2)
		throw Span::SpanTooSmallException();
	std::vector<int> tmp(this->__data);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::size_t i = 0; i < tmp.size() - 1; i++)
		min = std::min(min, tmp[i + 1] - tmp[i]);
	return min;
}

int Span::longestSpan(void) const
{
	if (this->__data.size() < 2)
		throw Span::SpanTooSmallException();
	std::vector<int>::const_iterator max = std::max_element(this->__data.begin(), this->__data.end());
	std::vector<int>::const_iterator min = std::min_element(this->__data.begin(), this->__data.end());
	return *max - *min;
}

void Span::addNumberRange(std::vector<int>::iterator begin,
						  std::vector<int>::iterator end)
{
	while (begin != end && this->__data.size() < this->__maxSize)
		this->__data.push_back(*begin++);
}

const char *Span::SpanIsFullException::what() const throw() { return "span is full"; }

const char *Span::SpanTooSmallException::what() const throw() { return "span too small"; }
