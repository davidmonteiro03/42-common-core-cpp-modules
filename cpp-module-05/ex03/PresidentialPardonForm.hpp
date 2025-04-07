/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:15:44 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:57:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &);
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);
	~PresidentialPardonForm();

	void execute(const Bureaucrat &) const;

private:
	static const unsigned int __GRADE_TO_SIGN;
	static const unsigned int __GRADE_TO_EXECUTE;
	std::string __target;
};
