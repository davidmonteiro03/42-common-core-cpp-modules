/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:53:47 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 09:13:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &data, const int &value) { return std::find(data.begin(), data.end(), value); }
