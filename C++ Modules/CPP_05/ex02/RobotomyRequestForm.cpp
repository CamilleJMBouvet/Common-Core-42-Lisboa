/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:53:58 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 22:43:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//----------------- Constructor/Destructor -----------------
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src), _target(src.getTarget())
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
		std::cout << BLUE << this->_target << GREY \
		" has been robotomized successfully" R << std::endl;
	else
		std::cout << GREY "Robotomy failed!" R << std::endl;
}
