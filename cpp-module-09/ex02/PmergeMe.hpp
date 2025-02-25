/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:35 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 10:04:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
private:
	PmergeMe();
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::vector<int> _copy;

public:
	PmergeMe(char **);
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();
	void execute(void);
	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
