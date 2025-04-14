/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:26:50 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/14 12:39:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <limits>

typedef std::vector<int> vector_t;
typedef std::deque<int> deque_t;

class PmergeMe
{
public:
	PmergeMe(const std::size_t &,
			 const char **);
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	void execute(void) const;

private:
	typedef std::vector<std::size_t> sequence_t;
	typedef std::pair<int, int> pair_t;
	typedef std::vector<pair_t> vector_pairs_t;
	typedef std::deque<pair_t> deque_pairs_t;

	vector_t __vector;
	deque_t __deque;

	PmergeMe(void);

	static bool __checkValue(const std::string &);
	static bool __comparePairs(const pair_t &,
							   const pair_t &);

	static sequence_t __generateJacobsthalSequence(const std::size_t &);
	static sequence_t __generateInsertionOrder(const std::size_t &);

	// VECTOR
	static vector_pairs_t __sortPairs(const vector_t &);
	static vector_t __pairsLeftPart(const vector_pairs_t &);
	static vector_t __pairsRightPart(const vector_pairs_t &);
	static vector_t __sort(const vector_t &);

	// DEQUE
	static deque_pairs_t __sortPairs(const deque_t &);
	static deque_t __pairsLeftPart(const deque_pairs_t &);
	static deque_t __pairsRightPart(const deque_pairs_t &);
	static deque_t __sort(const deque_t &);
};

std::ostream &operator<<(std::ostream &,
						 const vector_t &);

std::ostream &operator<<(std::ostream &,
						 const std::deque<int> &);
