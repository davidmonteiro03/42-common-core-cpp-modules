/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:15:44 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:53:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &);
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &) const;

private:
	static const unsigned int __GRADE_TO_SIGN;
	static const unsigned int __GRADE_TO_EXECUTE;
	std::string __target;
};
