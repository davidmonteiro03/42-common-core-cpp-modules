/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:23:14 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:37:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::__fractionalBits = 8;

Fixed::Fixed(void) : __value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int &value) : __value(value << Fixed::__fractionalBits) { std::cout << "Int constructor called" << std::endl; }

Fixed::Fixed(const float &value) : __value(roundf(value * (1 << Fixed::__fractionalBits))) { std::cout << "Float constructor called" << std::endl; }

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->__value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return this->__value; }

void Fixed::setRawBits(int const raw) { this->__value = raw; }

float Fixed::toFloat(void) const { return float(this->__value) / float(1 << Fixed::__fractionalBits); }

int Fixed::toInt(void) const { return this->__value >> Fixed::__fractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &f) { return os << f.toFloat(); }
