/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:17 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:36:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal(void);
	AAnimal(std::string);
	virtual ~AAnimal();
	AAnimal(const AAnimal &);
	AAnimal &operator=(const AAnimal &);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};
