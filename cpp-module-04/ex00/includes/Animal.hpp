/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:48:28 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:29:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(const std::string &);
	Animal(const Animal &);
	Animal &operator=(const Animal &);
	virtual ~Animal();

	const std::string &getType(void) const;
	void setType(const std::string &);

	virtual void makeSound(void) const;

protected:
	std::string _type;
};
