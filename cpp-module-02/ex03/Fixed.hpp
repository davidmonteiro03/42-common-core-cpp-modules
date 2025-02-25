/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:42 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 22:52:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedpoint;
	static const int _fractionalbits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float);
	Fixed &operator=(const Fixed &);
	~Fixed();

	// comparison operators
	bool operator>(const Fixed &) const;
	bool operator<(const Fixed &) const;
	bool operator>=(const Fixed &) const;
	bool operator<=(const Fixed &) const;
	bool operator==(const Fixed &) const;
	bool operator!=(const Fixed &) const;

	// arithmetic operators
	Fixed operator+(const Fixed &);
	Fixed operator-(const Fixed &);
	Fixed operator*(const Fixed &);
	Fixed operator/(const Fixed &);

	// increment/decrement operators
	Fixed operator++(int);
	Fixed &operator++(void);
	Fixed operator--(int);
	Fixed &operator--(void);

	// min/max
	static Fixed &min(Fixed &, Fixed &);
	static const Fixed &min(const Fixed &, const Fixed &);
	static Fixed &max(Fixed &, Fixed &);
	static const Fixed &max(const Fixed &, const Fixed &);

	int getRawBits(void) const;
	void setRawBits(int const);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &, Fixed const &);
