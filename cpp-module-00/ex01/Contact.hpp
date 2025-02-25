/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:18:39 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 21:38:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Contact
{
private:
	std::string first_name, last_name, phone_number, nickname, darkest_secret;

public:
	Contact(void);
	~Contact();
	std::string get_first_name(void) const;
	std::string get_last_name(void) const;
	std::string get_phone_number(void) const;
	std::string get_nickname(void) const;
	std::string get_darkest_secret(void) const;
	void set_first_name(std::string);
	void set_last_name(std::string);
	void set_phone_number(std::string);
	void set_nickname(std::string);
	void set_darkest_secret(std::string);
};
