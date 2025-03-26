/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:44:55 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:24:30 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//----------------- Constructor/Destructor -----------------
WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	this->wrong_type = src.getWrongType();
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		this->wrong_type = src.wrong_type;
	return (*this);
}

//--------------- Private attribute accessors --------------

std::string	WrongAnimal::getWrongType(void)const
{
	return (this->wrong_type);
}

//-------------------- Action functions --------------------
void	WrongAnimal::makeSound(void)const
{
	std::cout << GREEN "WrongAnimal " GREY "moohs" R << std::endl;
}
