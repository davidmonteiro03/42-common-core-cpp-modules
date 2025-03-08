/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:50:56 by dcaetano          #+#    #+#             */
/*   Updated: 2025/03/08 14:41:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _length(0), _storage(0) {}

Span::Span(unsigned int N) : _length(N), _storage(std::vector<int>()) {}

Span::Span(const Span &copy) : _length(copy._length)
{
	_storage.clear();
	_storage = copy._storage;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_length = other._length;
		_storage = other._storage;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value)
{
	if (_storage.size() == _length)
		throw VectorIsFullException();
	_storage.push_back(value);
}

void Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int dist = std::distance(begin, end);
	if (dist <= 0)
		return;
	while (begin != end)
	{
		if (_storage.size() == _length)
			return;
		_storage.push_back(*begin++);
	}
}

int Span::shortestSpan(void) const
{
	if (_storage.size() <= 1)
		throw TooFewElementsException();
	std::vector<int> tmp(_storage);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[0];
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		int curr = tmp[i], next = tmp[i + 1];
		if (next - curr < min)
			min = next - curr;
	}
	return min;
}

int Span::longestSpan(void) const
{
	if (_storage.size() <= 1)
		throw TooFewElementsException();
	std::vector<int>::const_iterator min, max;
	min = std::min_element(_storage.begin(), _storage.end());
	max = std::max_element(_storage.begin(), _storage.end());
	return *max - *min;
}

const char *Span::VectorIsFullException::what() const throw() { return "Span: VectorIsFullException"; }

const char *Span::TooFewElementsException::what() const throw() { return "Span: TooFewElementsException"; }
