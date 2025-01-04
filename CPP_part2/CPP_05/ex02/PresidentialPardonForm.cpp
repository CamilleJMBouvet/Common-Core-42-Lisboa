/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:53:39 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/11 22:44:07 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//----------------- Constructor/Destructor -----------------
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), \
_target("")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target): \
AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): \
AForm(src), _target(src.getTarget())
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

//---------------- Copy assignement operator ---------------
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	PresidentialPardonForm::getTarget()const
{
	return (this->_target);
}

//-------------------- Action functions --------------------
void	PresidentialPardonForm::executeAction()const
{
	std::cout << BLUE << this->_target << GREY \
	" has been pardoned by Zaphod Beeblebrox." R << std::endl;
}
