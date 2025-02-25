/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:28:07 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 22:55:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point(void);
	Point(const float, const float);
	Point(const Point &);
	Point &operator=(const Point &);
	~Point();

	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool bsp(Point const, Point const, Point const, Point const);
