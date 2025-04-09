/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:01:31 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 11:35:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(void);
	iterator end(void);

	const_iterator begin(void) const;
	const_iterator end(void) const;
	const_iterator cbegin(void) const;
	const_iterator cend(void) const;

	reverse_iterator rbegin(void);
	reverse_iterator rend(void);

	const_reverse_iterator rbegin(void) const;
	const_reverse_iterator rend(void) const;
	const_reverse_iterator crbegin(void) const;
	const_reverse_iterator crend(void) const;
};

#include "MutantStack.tpp"
