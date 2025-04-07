/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:38:03 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 18:31:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const unsigned int ShrubberyCreationForm::__GRADE_TO_SIGN = 145;
const unsigned int ShrubberyCreationForm::__GRADE_TO_EXECUTE = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("",
														   ShrubberyCreationForm::__GRADE_TO_SIGN,
														   ShrubberyCreationForm::__GRADE_TO_EXECUTE),
													 __target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target,
																				ShrubberyCreationForm::__GRADE_TO_SIGN,
																				ShrubberyCreationForm::__GRADE_TO_EXECUTE),
																		  __target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy),
																				  __target(copy.__target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->__target = other.__target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToSign() || executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	const std::string filename(this->__target + "_shrubbery");
	std::ofstream ofs(filename.c_str());
	if (ofs.fail())
		return;
	ofs << "          *" << std::endl;
	ofs << "         *|*" << std::endl;
	ofs << "        *\\|/*" << std::endl;
	ofs << "      *\\**|**/*" << std::endl;
	ofs << "    *\\***\\|/***/*" << std::endl;
	ofs << "     **\\**|**/**" << std::endl;
	ofs << "    *\\***\\|/***/*" << std::endl;
	ofs << "  *\\***\\**|**/***/*" << std::endl;
	ofs << "    *\\***\\|/***/*" << std::endl;
	ofs << "  *****\\**|**/*****" << std::endl;
	ofs << "*********\\|/*********" << std::endl;
	ofs << "         _|_" << std::endl;
}
