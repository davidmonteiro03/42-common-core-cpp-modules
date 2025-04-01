/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:36:37 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 18:57:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class PhoneBook
{
public:
	PhoneBook(void);
	PhoneBook(const PhoneBook &);
	PhoneBook &operator=(const PhoneBook &);
	~PhoneBook();

	void add(void);
	void search(void);

private:
	static const std::size_t MAX_CONTACTS = 8;
	Contact __contacts[MAX_CONTACTS];
	std::size_t __index;
	std::size_t __filled;
};
