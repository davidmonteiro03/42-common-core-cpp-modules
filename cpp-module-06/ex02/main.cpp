/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:29:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	for (std::size_t i = 0; i < 10; i++)
	{
		Base *generated = generate();
		identify(generated);
		identify(*generated);
		std::cout << std::endl;
		if (generated != NULL)
			delete generated;
	}
	return 0;
}
