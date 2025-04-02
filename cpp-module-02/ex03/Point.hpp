/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:55:54 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const float &, const float &);
	Point(const Point &);
	Point &operator=(const Point &);
	~Point();

	const Fixed &getX(void) const;
	const Fixed &getY(void) const;

private:
	const Fixed __x;
	const Fixed __y;
};

std::ostream &operator<<(std::ostream &, const Point &);

bool bsp(Point const, Point const, Point const, Point const);
