/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 07:48:28 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/14 13:15:46 by dcaetano         ###   ########.fr       */
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
	~WrongAnimal();

	const std::string &getType(void) const;
	void setType(const std::string &);

	void makeSound(void) const;

protected:
	std::string _type;
};
