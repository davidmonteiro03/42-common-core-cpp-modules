/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:43:06 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:46:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstring>

class Brain
{
public:
	Brain(void);
	Brain(const Brain &);
	Brain &operator=(const Brain &);
	~Brain();

private:
	std::string __ideas[100];
};
