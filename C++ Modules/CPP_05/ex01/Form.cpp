/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:27:47 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 22:42:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Form.hpp"

//----------------- Constructor/Destructor -----------------
Form::Form(): _name("Blank sheet"), _sign_grade(1), _exec_grade(1), _signed(false)
{}

Form::Form(std::string name, int sign_grade, int exec_grade): \
_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src): _name(src.getName()), _sign_grade(src.getSignGrade()), \
_exec_grade(src.getExecGrade()), _signed(false)
{}

Form::~Form()
{}

//---------------- Copy assignement operator ---------------
Form	&Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signed = src.isSigned();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	Form::getName()const
{
	return (this->_name);
}

int	Form::getSignGrade()const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade()const
{
	return (this->_exec_grade);
}

bool	Form::isSigned()const
{
	return (this->_signed);
}

//-------------------- Action functions --------------------
void	Form::beSigned(Bureaucrat &bur)
{
	if (this->_signed)
		throw Form::AlreadySignedException();
	if (bur.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

//----------------- Nested class functions -----------------
const char *Form::GradeTooHighException::what()const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what()const throw()
{
	return ("Grade too low!");
}

const char *Form::AlreadySignedException::what()const throw()
{
	return ("Form already signed!");
}

//--------------- Stream Operator Overload -----------------
std::ostream	&operator<<(std::ostream &o, const Form &instance)
{
	return (o << BLUE << instance.getName() << GREY " | form signing grade: " BLUE \
	<< instance.getSignGrade() << GREY " | execution grade: " BLUE \
	<< instance.getExecGrade() << GREY " | signed: " BLUE << instance.isSigned() << R);
}
