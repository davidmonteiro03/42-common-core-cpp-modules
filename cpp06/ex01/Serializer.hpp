/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:25:24 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 09:02:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_data
{
	std::string name;
	double age;
} t_data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);

public:
	~Serializer();
	static uintptr_t serialize(t_data *);
	static t_data *deserialize(uintptr_t);
};
