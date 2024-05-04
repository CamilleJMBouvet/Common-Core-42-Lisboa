/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/01 17:42:14 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//----------------- Constructor/Destructor -----------------
Dog::Dog(void)
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = src.getType();
	this->brain = new Brain(*src.getBrain());
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

//---------------- Copy assignement operator ---------------
Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*src.getBrain());
	}
	return (*this);
}

//--------------- Private attribute accessors --------------
Brain	*Dog::getBrain(void)const
{
	return(this->brain);
}

//-------------------- Action functions --------------------
void	Dog::makeSound(void)const
{
	std::cout << BLUE "Dog " GREY "barks" R << std::endl;
}
