/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:34 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/16 20:20:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//----------------- Constructor/Destructor -----------------
PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), \
_target("")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target): \
Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): \
Form(src), _target(src.getTarget())
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
	std::cout << BLUE << this->_target << GREEN \
	" has been pardoned by Zaphod Beeblebrox" R << std::endl;
}
