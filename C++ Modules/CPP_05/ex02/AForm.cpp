/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:52:57 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/11 22:32:57 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//----------------- Constructor/Destructor -----------------
AForm::AForm(): _name("Blank Sheet"), _sign_grade(1), _exec_grade(1), _signed(false)
{}

AForm::AForm(std::string name, int sign_grade, int exec_grade): _name(name), \
_sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw (AForm::GradeTooHighException());
	if (sign_grade > 150 || exec_grade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &src): _name(src.getName()), _sign_grade(src.getSignGrade()), \
_exec_grade(src.getExecGrade()), _signed(false)
{}

AForm::~AForm()
{}

//---------------- Copy assignement operator ---------------
AForm	&AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_signed = src.isSigned();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	AForm::getName()const
{
	return (this->_name);
}

int	AForm::getSignGrade()const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade()const
{
	return (this->_exec_grade);
}

bool	AForm::isSigned()const
{
	return (this->_signed);
}

//-------------------- Action functions --------------------
void	AForm::beSigned(Bureaucrat &bur)
{
	if (this->_signed)
		throw AForm::AlreadySignedException();
	if (bur.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

bool	AForm::execute(Bureaucrat const &executor)const
{
	try
	{
		if (!this->_signed)
			throw (AForm::FormNotSignedException());
		else if (executor.getGrade() > this->_exec_grade)
			throw (AForm::ExecutorTooLowException());
		this->executeAction();
	}
	catch (AForm::AFormExceptions &e)
	{
		std::cout << RED "Exception caught: " << e.what() << R << std::endl << std::endl;
		return (false);
	}
	return (true);
}

//----------------- Nested class functions -----------------
const char	*AForm::GradeTooHighException::what()const throw()
{
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what()const throw()
{
	return ("Grade too low!");
}

const char	*AForm::FormNotSignedException::what()const throw()
{
	return ("Form not signed!");
}

const char *AForm::AlreadySignedException::what()const throw()
{
	return ("Form already signed!");
}

const char	*AForm::ExecutorTooLowException::what()const throw()
{
	return ("Executor's grade is too low!");
}

//--------------- Stream Operator Overload -----------------
std::ostream	&operator<<(std::ostream &o, const AForm &instance)
{
	return (o << BLUE << instance.getName() << GREY " | form signing grade: " BLUE \
	<< instance.getSignGrade() << GREY " | execution grade: " BLUE \
	<< instance.getExecGrade() << GREY " | signed: " BLUE << instance.isSigned() << R);
}
