/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:43:06 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:43:54 by dcaetano         ###   ########.fr       */
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
	static const std::size_t __MAX_IDEAS = 100;
	std::string __ideas[__MAX_IDEAS];
};
