/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:38 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/30 19:45:51 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//----------------- Constructor/Destructor -----------------
Cat::Cat(void)
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = src.getType();
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
Cat	&Cat::operator=(Cat const &src)
{
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

//-------------------- Action functions --------------------
void	Cat::makeSound(void)const
{
	std::cout << BLUE "Cat " GREY "meows" R << std::endl;
}
