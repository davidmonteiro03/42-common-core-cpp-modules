/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:28 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:34:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phone_book.hpp"

PhoneBook::PhoneBook(void) : __index(0),
							 __filled(0) { std::memset(this->__contacts, 0, sizeof(this->__contacts)); }

PhoneBook::PhoneBook(const PhoneBook &copy) : __index(copy.__index),
											  __filled(copy.__filled) { std::memcpy(this->__contacts, copy.__contacts, sizeof(this->__contacts)); }

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		this->__index = other.__index;
		this->__filled = other.__filled;
		std::memcpy(this->__contacts, other.__contacts, sizeof(this->__contacts));
	}
	return *this;
}

PhoneBook::~PhoneBook() { std::cout << "The contacts were lost forever!" << std::endl; }

void PhoneBook::add(void)
{
	std::string firstName = "";
	std::string lastName = "";
	std::string nickname = "";
	std::string phoneNumber = "";
	std::string darkestSecret = "";
	std::cout << "Enter your first name: ";
	std::cin >> firstName;
	std::cout << "Enter your last name: ";
	std::cin >> lastName;
	std::cout << "Enter your nickname: ";
	std::cin >> nickname;
	std::cout << "Enter your phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter your darkest secret: ";
	std::cin >> darkestSecret;
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "A contact can't have empty fields." << std::endl;
		return;
	}
	this->__contacts[this->__index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->__index = (this->__index + 1) % PhoneBook::MAX_CONTACTS;
	if (this->__filled < PhoneBook::MAX_CONTACTS)
		this->__filled++;
}

static std::string trimString(const std::string &str, const std::size_t &size)
{
	std::string result = str.substr(0, size - (str.size() > size));
	if (str.size() > size)
		result += ".";
	return result;
}

void PhoneBook::search(void)
{
	if (this->__filled == 0)
		return;
	const std::size_t trunSize = 10;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (std::size_t i = 0; i < PhoneBook::MAX_CONTACTS; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i
				  << "|" << std::right << std::setw(10) << trimString(this->__contacts[i].getFirstName(), trunSize)
				  << "|" << std::right << std::setw(10) << trimString(this->__contacts[i].getLastName(), trunSize)
				  << "|" << std::right << std::setw(10) << trimString(this->__contacts[i].getNickname(), trunSize)
				  << "|" << std::endl;
	}
	std::size_t index = PhoneBook::MAX_CONTACTS;
	std::cout << "Enter the index to search: ";
	std::cin >> index;
	if (index > this->__filled - 1)
	{
		std::cout << "That index is out of range." << std::endl;
		return;
	}
	std::cout << "First Name: " << this->__contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->__contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->__contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->__contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->__contacts[index].getDarkestSecret() << std::endl;
}
