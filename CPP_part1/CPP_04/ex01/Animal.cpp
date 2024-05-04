/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:14 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/30 19:21:39 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//----------------- Constructor/Destructor -----------------
Animal::Animal(void)
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	this->type = src.getType();
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
Animal	&Animal::operator=(Animal const &src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	Animal::getType(void)const
{
	return (this->type);
}

//-------------------- Action functions --------------------
void	Animal::makeSound(void)const
{
	std::cout << BLUE "Animal " GREY "makes weird noises" R << std::endl;
}
