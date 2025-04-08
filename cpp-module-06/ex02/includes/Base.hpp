/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:15:18 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:23:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	Base(void);
	virtual ~Base();
};

Base *generate(void);

void identify(Base *);
void identify(Base &);
