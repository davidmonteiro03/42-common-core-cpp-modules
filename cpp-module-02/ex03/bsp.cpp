/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:04:05 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 14:57:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream &operator<<(std::ostream &os, const Point &p) { return os << "(" << p.getX() << ", " << p.getY() << ")"; }

static Fixed ft_abs(const Fixed &f) { return f >= 0 ? f : f * -1; }

static Fixed triangleArea(const Point &a, const Point &b, const Point &c)
{
	const Fixed &___x1 = a.getX(), ___y1 = a.getY();
	const Fixed &___x2 = b.getX(), ___y2 = b.getY();
	const Fixed &___x3 = c.getX(), ___y3 = c.getY();
	return ft_abs(___x1 * (___y2 - ___y3) + ___x2 * (___y3 - ___y1) + ___x3 * (___y1 - ___y2)) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Fixed &areaABC = triangleArea(a, b, c);
	const Fixed &areaABP = triangleArea(a, b, point);
	const Fixed &areaACP = triangleArea(a, c, point);
	const Fixed &areaBCP = triangleArea(b, c, point);
	const bool &inEdges = areaABP == 0 || areaACP == 0 || areaBCP == 0;
	const bool &inside = areaABP + areaACP + areaBCP == areaABC;
	return inEdges == false && inside == true;
}
