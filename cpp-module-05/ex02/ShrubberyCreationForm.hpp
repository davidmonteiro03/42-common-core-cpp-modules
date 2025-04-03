/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:15:44 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 17:22:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &) const;

private:
	static const unsigned int __GRADE_TO_SIGN;
	static const unsigned int __GRADE_TO_EXECUTE;
	std::string __target;
};
