/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:36 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 22:42:03 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//----------------- Constructor/Destructor -----------------
Bureaucrat::Bureaucrat(void): _name("anonymous"), _grade(0)
{}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName()), _grade(src.getGrade())
{}

Bureaucrat::~Bureaucrat(void)
{}

//---------------- Operator overloads ---------------
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string Bureaucrat::getName(void)const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

//-------------------- Action functions --------------------
void Bureaucrat::increment(void)
{
	if (this->_grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(void)
{
	if (this->_grade +1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

//----------------- Nested class functions -----------------
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

//--------------- Stream Operator Overload -----------------
std::ostream &operator<<(std::ostream &o, const Bureaucrat &instance)
{
	return (o << BLUE << instance.getName() << GREY ", bureaucrat grade " \
	BLUE << instance.getGrade() << R);
}
