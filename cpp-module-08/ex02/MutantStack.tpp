/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:01:31 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/09 11:35:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) { return this->c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const { return this->c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const { return this->c.cbegin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const { return this->c.cend(); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void) { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void) { return this->c.rend(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin(void) const { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend(void) const { return this->c.rend(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void) const { return this->c.crbegin(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void) const { return this->c.crend(); }
