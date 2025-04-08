/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:54:52 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:02:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &) {}

Serializer &Serializer::operator=(const Serializer &) { return *this; }

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }
