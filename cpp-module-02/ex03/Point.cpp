/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:58:23 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 13:05:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : __x(0), __y(0) {}

Point::Point(const float &x, const float &y) : __x(x), __y(y) {}

Point::Point(const Point &copy) : __x(copy.__x), __y(copy.__y) {}

Point &Point::operator=(const Point &) { return *this; }

Point::~Point() {}

const Fixed &Point::getX(void) const { return this->__x; }

const Fixed &Point::getY(void) const { return this->__y; }
