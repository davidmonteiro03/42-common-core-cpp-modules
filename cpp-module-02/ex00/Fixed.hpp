/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:20:47 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:35:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const);

private:
	int __value;
	static const int __fractionalBits;
};
