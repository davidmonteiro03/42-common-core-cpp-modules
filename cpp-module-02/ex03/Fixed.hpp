/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:20:47 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 12:46:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int &);
	Fixed(const float &);
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const);

	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed &) const;
	bool operator<(const Fixed &) const;
	bool operator>=(const Fixed &) const;
	bool operator<=(const Fixed &) const;
	bool operator==(const Fixed &) const;
	bool operator!=(const Fixed &) const;

	Fixed operator+(const Fixed &) const;
	Fixed operator-(const Fixed &) const;
	Fixed operator*(const Fixed &) const;
	Fixed operator/(const Fixed &) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &, Fixed &);
	static const Fixed &min(const Fixed &, const Fixed &);
	static Fixed &max(Fixed &, Fixed &);
	static const Fixed &max(const Fixed &, const Fixed &);

private:
	int __value;
	static const int __fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &, const Fixed &);
