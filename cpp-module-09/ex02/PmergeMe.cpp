/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:30:48 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/14 12:53:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : __vector(),
						   __deque() {}

PmergeMe::PmergeMe(const std::size_t &size,
				   const char **args) : __vector(),
										__deque()
{
	for (std::size_t i = 0; i < size; i++)
	{
		if (!PmergeMe::__checkValue(std::string(args[i])))
			throw std::exception();
		const int num = std::atoi(args[i]);
		this->__vector.push_back(num);
		this->__deque.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe &copy) : __vector(copy.__vector),
										   __deque(copy.__deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->__vector = other.__vector;
		this->__deque = other.__deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::__checkValue(const std::string &str)
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
	return i == str.size() && hasDigits;
}

bool PmergeMe::__comparePairs(const PmergeMe::pair_t &a,
							  const PmergeMe::pair_t &b) { return a.first < b.first; }

PmergeMe::sequence_t PmergeMe::__generateJacobsthalSequence(const std::size_t &n)
{
	PmergeMe::sequence_t result;
	result.push_back(0);
	if (n == 0)
		return result;
	result.push_back(1);
	if (n == 1)
		return result;
	std::size_t r0 = result[0], r1 = result[1];
	while (true)
	{
		std::size_t next = r1 + 2 * r0;
		if (next > n)
			break;
		result.push_back(next);
		r0 = r1;
		r1 = next;
	}
	return result;
}

PmergeMe::sequence_t PmergeMe::__generateInsertionOrder(const std::size_t &n)
{
	PmergeMe::sequence_t result;
	std::vector<bool> used(n, false);
	PmergeMe::sequence_t jacobsthalSequence = __generateJacobsthalSequence(n);
	for (PmergeMe::sequence_t::iterator it = jacobsthalSequence.begin(); it != jacobsthalSequence.end(); it++)
	{
		if (*it < n && used[*it] == false)
		{
			result.push_back(*it);
			used[*it] = true;
		}
	}
	for (std::size_t i = 0; i < used.size(); i++)
		if (used[i] == false)
			result.push_back(i);
	return result;
}

/* ************************************************************************** */
/*                                   VECTOR                                   */
/* ************************************************************************** */

PmergeMe::vector_pairs_t PmergeMe::__sortPairs(const vector_t &vector)
{
	PmergeMe::vector_pairs_t result;
	for (vector_t::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		int ___ = *it++;
		if (it == vector.end())
			break;
		result.push_back(PmergeMe::pair_t(___, *it));
	}
	for (PmergeMe::vector_pairs_t::iterator it = result.begin(); it != result.end(); it++)
		if (it->first < it->second)
			std::swap(it->first, it->second);
	std::sort(result.begin(), result.end(), PmergeMe::__comparePairs);
	return result;
}

vector_t PmergeMe::__pairsLeftPart(const PmergeMe::vector_pairs_t &pairs)
{
	vector_t result;
	for (PmergeMe::vector_pairs_t::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		result.push_back(it->first);
	return result;
}

vector_t PmergeMe::__pairsRightPart(const PmergeMe::vector_pairs_t &pairs)
{
	vector_t result;
	for (PmergeMe::vector_pairs_t::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		result.push_back(it->second);
	return result;
}

vector_t PmergeMe::__sort(const vector_t &vector)
{
	if (vector.size() == 1)
		return vector;
	PmergeMe::vector_pairs_t sortedPairs = PmergeMe::__sortPairs(vector);
	vector_t mainChain = PmergeMe::__pairsLeftPart(sortedPairs);
	vector_t pendent = PmergeMe::__pairsRightPart(sortedPairs);
	sequence_t insertionOrder = PmergeMe::__generateInsertionOrder(pendent.size());
	for (PmergeMe::sequence_t::iterator it = insertionOrder.begin(); it != insertionOrder.end(); it++)
	{
		const int &valueToInsert = pendent[*it];
		vector_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
		mainChain.insert(pos, valueToInsert);
	}
	if (vector.size() % 2 == 1)
	{
		const int &last = vector.back();
		vector_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(pos, last);
	}
	return mainChain;
}

/* ************************************************************************** */
/*                                   DEQUE                                    */
/* ************************************************************************** */

PmergeMe::deque_pairs_t PmergeMe::__sortPairs(const deque_t &deque)
{
	PmergeMe::deque_pairs_t result;
	for (deque_t::const_iterator it = deque.begin(); it != deque.end(); it++)
	{
		int ___ = *it++;
		if (it == deque.end())
			break;
		result.push_back(pair_t(___, *it));
	}
	for (PmergeMe::deque_pairs_t::iterator it = result.begin(); it != result.end(); it++)
		if (it->first < it->second)
			std::swap(it->first, it->second);
	std::sort(result.begin(), result.end(), PmergeMe::__comparePairs);
	return result;
}

deque_t PmergeMe::__pairsLeftPart(const PmergeMe::deque_pairs_t &pairs)
{
	deque_t result;
	for (PmergeMe::deque_pairs_t::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		result.push_back(it->first);
	return result;
}

deque_t PmergeMe::__pairsRightPart(const PmergeMe::deque_pairs_t &pairs)
{
	deque_t result;
	for (PmergeMe::deque_pairs_t::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		result.push_back(it->second);
	return result;
}

deque_t PmergeMe::__sort(const deque_t &deque)
{
	if (deque.size() == 1)
		return deque;
	PmergeMe::deque_pairs_t sortedPairs = PmergeMe::__sortPairs(deque);
	deque_t mainChain = PmergeMe::__pairsLeftPart(sortedPairs);
	deque_t pendent = PmergeMe::__pairsRightPart(sortedPairs);
	PmergeMe::sequence_t insertionOrder = PmergeMe::__generateInsertionOrder(pendent.size());
	for (PmergeMe::sequence_t::iterator it = insertionOrder.begin(); it != insertionOrder.end(); it++)
	{
		const int &valueToInsert = pendent[*it];
		deque_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
		mainChain.insert(pos, valueToInsert);
	}
	if (deque.size() % 2 == 1)
	{
		const int &last = deque.back();
		deque_t::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(pos, last);
	}
	return mainChain;
}

void PmergeMe::execute(void) const
{
	std::clock_t startClock = clock();
	vector_t sortedVector = PmergeMe::__sort(this->__vector);
	std::clock_t middleClock = clock();
	deque_t sortedDeque = PmergeMe::__sort(this->__deque);
	std::clock_t stopClock = clock();
	long double timeToSortVector = (static_cast<long double>(middleClock) - static_cast<long double>(startClock)) / static_cast<long double>(CLOCKS_PER_SEC);
	long double timeToSortDeque = (static_cast<long double>(stopClock) - static_cast<long double>(middleClock)) / static_cast<long double>(CLOCKS_PER_SEC);
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << "Before: " << this->__vector << std::endl;
	std::cout << "After: " << sortedVector << std::endl;
	std::cout << "Time to process a range of " << this->__vector.size() << " elements with std::vector : " << timeToSortVector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->__deque.size() << " elements with std::deque : " << timeToSortDeque << " us" << std::endl;
}

std::ostream &operator<<(std::ostream &os,
						 const vector_t &vector)
{
	for (vector_t::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (it != vector.begin())
			os << " ";
		os << *it;
	}
	return os;
}

std::ostream &operator<<(std::ostream &os,
						 const deque_t &deque)
{
	for (deque_t::const_iterator it = deque.begin(); it != deque.end(); it++)
	{
		if (it != deque.begin())
			os << " ";
		os << *it;
	}
	return os;
}
