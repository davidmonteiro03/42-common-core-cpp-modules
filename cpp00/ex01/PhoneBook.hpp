/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:07:19 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 21:42:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int index;

public:
	PhoneBook(void);
	~PhoneBook(void);
	void add_contact(void);
	void search_contact(void);
	void print_contact(Contact contact);
	Contact get_contact(int index);
};
