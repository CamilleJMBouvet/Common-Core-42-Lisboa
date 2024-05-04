/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:09:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/02 15:07:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//----------------- Constructor/Destructor -----------------
Cure::Cure(void)
{
	this->type = "cure";
}

Cure::Cure(Cure const &src)
{
	this->type = src.getType();
}

Cure::Cure(std::string const &type)
{
	this->type = type;
}

Cure::~Cure(void)
{}

//---------------- Copy assignement operator ---------------
Cure	&Cure::operator=(Cure const &src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

//-------------------- Action functions --------------------
Cure	*Cure::clone()const
{
	Cure *cure = new Cure();
	return (cure);
}

void Cure::use(ICharacter &target)
{
	std::cout << GREY "* heals " PURPLE << target.getName() \
	<< GREY "'s wounds *" R << std::endl;
}
