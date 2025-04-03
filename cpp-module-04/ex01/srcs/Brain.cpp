/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:45:41 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:47:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void) { std::memset(this->__ideas, 0, sizeof(this->__ideas)); }

Brain::Brain(const Brain &copy) { std::memcpy(this->__ideas, copy.__ideas, sizeof(this->__ideas)); }

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
		std::memcpy(this->__ideas, other.__ideas, sizeof(this->__ideas));
	return *this;
}

Brain::~Brain() {}
