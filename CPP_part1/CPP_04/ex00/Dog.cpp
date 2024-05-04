/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/30 19:45:54 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//----------------- Constructor/Destructor -----------------
Dog::Dog(void)
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = src.getType();
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

//-------------------- Action functions --------------------
void	Dog::makeSound(void)const
{
	std::cout << BLUE "Dog " GREY "barks" R << std::endl;
}
