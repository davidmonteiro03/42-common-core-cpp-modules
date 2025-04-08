/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:35:53 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/08 18:52:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
void iter(T *array, const std::size_t &len, void (*func)(T &))
{
	if (array == NULL || len == 0)
		return ;
	for (std::size_t i = 0; i < len; i++)
		func(array[i]);
}
