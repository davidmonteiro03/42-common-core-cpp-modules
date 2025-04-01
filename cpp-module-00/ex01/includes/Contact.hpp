/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:36:37 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/01 18:12:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Contact
{
public:
	Contact(void);
	Contact(const std::string &,
			const std::string &,
			const std::string &,
			const std::string &,
			const std::string &);
	Contact(const Contact &);
	Contact &operator=(const Contact &);
	~Contact();

	const std::string &getFirstName(void) const;
	const std::string &getLastName(void) const;
	const std::string &getNickname(void) const;
	const std::string &getPhoneNumber(void) const;
	const std::string &getDarkestSecret(void) const;

	void setFirstName(const std::string &);
	void setLastName(const std::string &);
	void setNickname(const std::string &);
	void setPhoneNumber(const std::string &);
	void setDarkestSecret(const std::string &);

private:
	std::string __firstName;
	std::string __lastName;
	std::string __nickname;
	std::string __phoneNumber;
	std::string __darkestSecret;
};
