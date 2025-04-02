/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 5)
	{
		std::cerr << "usage: " << argv[0] << " <ax ay> <bx by> <cx cy> <px py>" << std::endl;
		return 1;
	}

	float ax = 0, ay = 0, bx = 0, by = 0, cx = 0, cy = 0, px = 0, py = 0;
	std::stringstream aSs(argv[1]), bSs(argv[2]), cSs(argv[3]), pSs(argv[4]);

	aSs >> ax >> ay;
	bSs >> bx >> by;
	cSs >> cx >> cy;
	pSs >> px >> py;

	Point a(ax, ay), b(bx, by), c(cx, cy), p(px, py);
	bool bspResult = bsp(a, b, c, p);

	std::cout << "=======================" << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "P = " << p << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "BSP = " << (bspResult == true ? "TRUE" : "FALSE") << std::endl;
	std::cout << std::endl;

	return 0;
}
