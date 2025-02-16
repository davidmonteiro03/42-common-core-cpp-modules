/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:42 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 22:40:42 by dcaetano         ###   ########.fr       */
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
	int getRawBits(void) const;
	void setRawBits(int const);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &, Fixed const &);
