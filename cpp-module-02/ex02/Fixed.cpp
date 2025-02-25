/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:13:33 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 22:45:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedpoint(0) {}

Fixed::Fixed(const int n) : _fixedpoint(n << _fractionalbits) {}

Fixed::Fixed(const float n) : _fixedpoint(roundf(n * (1 << this->_fractionalbits))) {}

Fixed::Fixed(const Fixed &ref) { *this = ref; }

Fixed &Fixed::operator=(const Fixed &ref)
{
	if (this != &ref)
		this->_fixedpoint = ref.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

// comparison operators

bool Fixed::operator>(const Fixed &ref) const { return this->toFloat() > ref.toFloat(); }

bool Fixed::operator<(const Fixed &ref) const { return this->toFloat() < ref.toFloat(); }

bool Fixed::operator>=(const Fixed &ref) const { return this->toFloat() >= ref.toFloat(); }

bool Fixed::operator<=(const Fixed &ref) const { return this->toFloat() <= ref.toFloat(); }

bool Fixed::operator==(const Fixed &ref) const { return this->toFloat() == ref.toFloat(); }

bool Fixed::operator!=(const Fixed &ref) const { return this->toFloat() != ref.toFloat(); }

// arithmetic operators

Fixed Fixed::operator+(const Fixed &ref) { return Fixed(this->toFloat() + ref.toFloat()); }

Fixed Fixed::operator-(const Fixed &ref) { return Fixed(this->toFloat() - ref.toFloat()); }

Fixed Fixed::operator*(const Fixed &ref) { return Fixed(this->toFloat() * ref.toFloat()); }

Fixed Fixed::operator/(const Fixed &ref) { return Fixed(this->toFloat() / ref.toFloat()); }

// increment/decrement operators

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	tmp._fixedpoint = this->_fixedpoint++;
	return tmp;
}

Fixed &Fixed::operator++(void)
{
	++this->_fixedpoint;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	tmp._fixedpoint = this->_fixedpoint--;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	--this->_fixedpoint;
	return *this;
}

// min/max

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	return ref2;
}

const Fixed &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 < ref2)
		return ref1;
	return ref2;
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	return ref2;
}

const Fixed &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1 > ref2)
		return ref1;
	return ref2;
}

int Fixed::getRawBits(void) const { return this->_fixedpoint; }

void Fixed::setRawBits(int const raw) { this->_fixedpoint = raw; }

float Fixed::toFloat(void) const { return float(this->_fixedpoint) / float(1 << this->_fractionalbits); }

int Fixed::toInt(void) const { return this->_fixedpoint >> _fractionalbits; }

std::ostream &operator<<(std::ostream &out, Fixed const &in) { return out << in.toFloat(); }
