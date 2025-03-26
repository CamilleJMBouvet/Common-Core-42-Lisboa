/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:09:39 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/02 15:07:43 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

//----------------- Constructor/Destructor -----------------
Ice::Ice(void)
{
	this->type = "ice";
}

Ice::Ice(Ice const &src)
{
	this->type = src.getType();
}

Ice::Ice(std::string const &type)
{
	this->type = type;
}

Ice::~Ice(void)
{}

//---------------- Copy assignement operator ---------------
Ice	&Ice::operator=(Ice const &src)
{
	if (this != &src)
		this->type = src.getType();
	return (*this);
}

//-------------------- Action functions --------------------
Ice	*Ice::clone()const
{
	Ice *ice = new Ice();
	return (ice);
}

void Ice::use(ICharacter &target)
{
	std::cout << GREY "* shoots and ice bolt at " PURPLE << target.getName() \
	<< GREY " *" R << std::endl;
}
