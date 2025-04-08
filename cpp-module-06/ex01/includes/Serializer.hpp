/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:54:52 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:05:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdint.h>

typedef struct s_data
{
	std::string name;
	unsigned int age;
} Data;

class Serializer
{
public:
	static uintptr_t serialize(Data *);
	static Data *deserialize(uintptr_t);

private:
	Serializer(void);
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	~Serializer();
};
