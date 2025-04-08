/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:35:53 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 19:35:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstring>
#include <exception>

template <typename T>
class Array
{
public:
	Array(void);
	Array(const unsigned int &);
	Array(const Array &);
	Array &operator=(const Array &);
	~Array();

	T &operator[](const unsigned int &);

	const unsigned int &size(void) const;

	class IndexOutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	T *__data;
	unsigned int __size;
};

#include "Array.tpp"
