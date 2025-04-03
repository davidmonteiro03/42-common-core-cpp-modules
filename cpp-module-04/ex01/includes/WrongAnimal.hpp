/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:48:28 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:33:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const std::string &);
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);
	virtual ~WrongAnimal();

	const std::string &getType(void) const;
	void setType(const std::string &);

	virtual void makeSound(void) const;

protected:
	std::string _type;
};
