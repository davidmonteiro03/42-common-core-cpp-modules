/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:42 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 18:13:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phone_book.hpp"

Contact::Contact(void) : __firstName(""),
						 __lastName(""),
						 __nickname(""),
						 __phoneNumber(""),
						 __darkestSecret("") {}

Contact::Contact(const std::string &firstName,
				 const std::string &lastName,
				 const std::string &nickname,
				 const std::string &phoneNumber,
				 const std::string &darkestSecret) : __firstName(firstName),
													 __lastName(lastName),
													 __nickname(nickname),
													 __phoneNumber(phoneNumber),
													 __darkestSecret(darkestSecret) {}

Contact::Contact(const Contact &copy) : __firstName(copy.__firstName),
										__lastName(copy.__lastName),
										__nickname(copy.__nickname),
										__phoneNumber(copy.__phoneNumber),
										__darkestSecret(copy.__darkestSecret) {}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		this->__firstName = other.__firstName;
		this->__lastName = other.__lastName;
		this->__nickname = other.__nickname;
		this->__phoneNumber = other.__phoneNumber;
		this->__darkestSecret = other.__darkestSecret;
	}
	return *this;
}

Contact::~Contact() {}

const std::string &Contact::getFirstName(void) const { return this->__firstName; }

const std::string &Contact::getLastName(void) const { return this->__lastName; }

const std::string &Contact::getNickname(void) const { return this->__nickname; }

const std::string &Contact::getPhoneNumber(void) const { return this->__phoneNumber; }

const std::string &Contact::getDarkestSecret(void) const { return this->__darkestSecret; }

void Contact::setFirstName(const std::string &firstName) { this->__firstName = firstName; }

void Contact::setLastName(const std::string &lastName) { this->__lastName = lastName; }

void Contact::setNickname(const std::string &nickname) { this->__nickname = nickname; }

void Contact::setPhoneNumber(const std::string &phoneNumber) { this->__phoneNumber = phoneNumber; }

void Contact::setDarkestSecret(const std::string &darkestSecret) { this->__darkestSecret = darkestSecret; }
