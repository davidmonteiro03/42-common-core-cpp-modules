/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:36 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 10:59:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
public:
	Harl(void);
	Harl(const Harl &);
	Harl &operator=(const Harl &);
	~Harl();

	void complain(std::string);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};
