/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:35:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/14 08:54:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pm(static_cast<std::size_t>(argc - 1),
					(const char **)(argv + 1));
		pm.execute();
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
