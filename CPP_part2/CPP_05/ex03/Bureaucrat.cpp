/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:42 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/16 20:18:24 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//----------------- Constructor/Destructor -----------------
Bureaucrat::Bureaucrat(): _name("Anonymous"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName()), _grade(src.getGrade())
{}

Bureaucrat::~Bureaucrat()
{}

//---------------- Copy assignement operator ---------------
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	Bureaucrat::getName()const
{
	return (this->_name);
}

int	Bureaucrat::getGrade()const
{
	return (this->_grade);
}

//-------------------- Action functions --------------------
void	Bureaucrat::increment()
{
	if (this->_grade -1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrement()
{
	if (this->_grade +1 > 150)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade++;
}

bool	Bureaucrat::signForm(Form &form)
{
	try
	{
		std::cout << BLUE << this->_name << GREY;
		form.beSigned(*this);
		std::cout << " signed form " BLUE << form.getName() << R << std::endl;
	}
	catch (Form::FormExceptions &e)
	{
		std::cout << " couldn't sign " BLUE << form.getName() \
		<< GREY " because: " << std::endl;
		std::cerr << RED "Exception caught - " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	Bureaucrat::executeForm(Form const &form)
{
	if (form.execute(*this))
		return (true);
	return (false);
}

//----------------- Nested class functions -----------------
const char *Bureaucrat::GradeTooHighException::what()const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what()const throw()
{
	return ("Grade too low!");
}

//--------------- Stream Operator Overload -----------------
std::ostream	&operator<<(std::ostream &o, const Bureaucrat &instance)
{
	return (o << BLUE << instance.getName() << GREY ", Bureaucrat grade " \
	BLUE << instance.getGrade() << R);
}
