/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:20:47 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 11:37:56 by dcaetano         ###   ########.fr       */
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

private:
	int __value;
	static const int __fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &, const Fixed &);
