/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:51:31 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/01 18:18:16 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//----------------- Constructor/Destructor -----------------
Cat::Cat(void)
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = src.getType();
	this->brain = new Brain(*src.getBrain());
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

//---------------- Copy assignement operator ---------------
Cat	&Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		AAnimal::operator=(src);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*src.getBrain());
	}
	return (*this);
}

//--------------- Private attribute accessors --------------
Brain	*Cat::getBrain(void)const
{
	return (this->brain);
}

//-------------------- Action functions --------------------
void	Cat::makeSound(void)const
{
	std::cout << BLUE "Cat " GREY "meows" R << std::endl;
}
