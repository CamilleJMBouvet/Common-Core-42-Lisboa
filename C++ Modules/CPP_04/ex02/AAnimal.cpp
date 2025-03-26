/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:14 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/01 18:12:27 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//----------------- Constructor/Destructor -----------------
AAnimal::AAnimal(void)
{
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	this->type = src.getType();
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
AAnimal	&AAnimal::operator=(AAnimal const &src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	AAnimal::getType(void)const
{
	return (this->type);
}

//-------------------- Action functions --------------------
void	AAnimal::makeSound(void)const
{
	std::cout << BLUE "AAnimal " GREY "makes weird noises" R << std::endl;
}
