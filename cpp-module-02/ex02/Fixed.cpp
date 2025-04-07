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

Fixed::Fixed(void) : __value(0) {}

Fixed::Fixed(const int &value) : __value(value << Fixed::__fractionalBits) {}

Fixed::Fixed(const float &value) : __value(roundf(value * (1 << Fixed::__fractionalBits))) {}

Fixed::Fixed(const Fixed &copy) { *this = copy; }

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->__value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->__value; }

void Fixed::setRawBits(int const raw) { this->__value = raw; }

float Fixed::toFloat(void) const { return float(this->__value) / float(1 << Fixed::__fractionalBits); }

int Fixed::toInt(void) const { return this->__value >> Fixed::__fractionalBits; }

bool Fixed::operator>(const Fixed &other) const { return this->toFloat() > other.toFloat(); }

bool Fixed::operator<(const Fixed &other) const { return this->toFloat() < other.toFloat(); }

bool Fixed::operator>=(const Fixed &other) const { return this->toFloat() >= other.toFloat(); }

bool Fixed::operator<=(const Fixed &other) const { return this->toFloat() <= other.toFloat(); }

bool Fixed::operator==(const Fixed &other) const { return this->toFloat() == other.toFloat(); }

bool Fixed::operator!=(const Fixed &other) const { return this->toFloat() != other.toFloat(); }

Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }

Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }

Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }

Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed &Fixed::operator++(void)
{
	this->__value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->__value++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	this->__value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->__value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a <= b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return a <= b ? a : b; }

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a >= b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return a >= b ? a : b; }

std::ostream &operator<<(std::ostream &os, const Fixed &f) { return os << f.toFloat(); }
