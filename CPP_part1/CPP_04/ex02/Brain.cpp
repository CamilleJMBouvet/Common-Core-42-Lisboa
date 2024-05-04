/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:51:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/01 18:15:40 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//----------------- Constructor/Destructor -----------------
Brain::Brain(void)
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

//---------------- Copy assignement operator ---------------
Brain	&Brain::operator=(Brain const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}
