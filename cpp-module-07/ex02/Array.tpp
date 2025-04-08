/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:35:53 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 19:55:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->__data = NULL;
	this->__size = 0;
}

template <typename T>
Array<T>::Array(const unsigned int &n)
{
	this->__data = NULL;
	this->__size = 0;
	if (n > 0)
	{
		this->__data = new T[n];
		if (this->__data != NULL)
		{
			this->__size = n;
			std::memset(this->__data, 0, this->__size * sizeof(T));
		}
	}
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	this->__data = NULL;
	this->__size = 0;
	if (copy.__data != NULL && copy.__size > 0)
	{
		this->__data = new T[copy.__size];
		if (this->__data != NULL)
		{
			this->__size = copy.__size;
			for (std::size_t i = 0; i < this->__size; i++)
				this->__data[i] = copy.__data[i];
		}
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (this->__data != NULL && this->__size > 0)
			delete[] this->__data;
		this->__data = NULL;
		this->__size = 0;
		if (other.__data != NULL && other.__size > 0)
		{
			this->__data = new T[other.__size];
			if (this->__data != NULL)
			{
				this->__size = other.__size;
				for (std::size_t i = 0; i < this->__size; i++)
					this->__data[i] = other.__data[i];
			}
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->__data != NULL && this->__size > 0)
		delete[] this->__data;
}

template <typename T>
T &Array<T>::operator[](const unsigned int &index)
{
	if (index >= this->__size)
		throw Array<T>::IndexOutOfBoundsException();
	return this->__data[index];
}

template <typename T>
const unsigned int &Array<T>::size(void) const { return this->__size; }

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw() { return "index out of bounds"; }
