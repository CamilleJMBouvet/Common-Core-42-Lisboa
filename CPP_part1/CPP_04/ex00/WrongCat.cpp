/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:45:19 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:24:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//----------------- Constructor/Destructor -----------------
WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->wrong_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	this->wrong_type = src.getWrongType();
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

//-------------------- Action functions --------------------
void	WrongCat::makeSound(void)const
{
	std::cout << GREEN "WrongCat " GREY "meows" R << std::endl;
}
