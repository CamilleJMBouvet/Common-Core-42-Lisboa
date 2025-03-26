/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:30 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/16 20:20:42 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//----------------- Constructor/Destructor -----------------
RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), _target("")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form(src), _target(src.getTarget())
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

//---------------- Copy assignement operator ---------------
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	RobotomyRequestForm::getTarget()const
{
	return (this->_target);
}

//-------------------- Action functions --------------------
void	RobotomyRequestForm::executeAction()const
{
	std::cout << GREY "*drilling noises*" R << std::endl;

	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << BLUE << this->_target << GREEN \
		" has been robotomized successfullly" R << std::endl;
	else
		std::cout << GREEN "Robotomy failed!" R << std::endl;
}
