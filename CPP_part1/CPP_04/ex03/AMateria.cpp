/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:07:15 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/02 15:16:14 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//----------------- Constructor/Destructor -----------------
AMateria::AMateria(void)
{}

AMateria::AMateria(AMateria const &src)
{
	this->type = src.getType();
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::~AMateria(void)
{}

//---------------- Copy assignement operator ---------------
AMateria	&AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string const	&AMateria::getType()const
{
	return (this->type);
}

//-------------------- Action functions --------------------
void	AMateria::use(ICharacter &target)
{
	(void)target;
}
