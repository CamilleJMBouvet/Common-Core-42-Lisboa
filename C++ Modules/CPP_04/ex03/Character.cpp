/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:10:01 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 15:38:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//----------------- Constructor/Destructor -----------------
Character::Character(void)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &src): name(src.getName())
{
	for (int i = 0; i < 4; i++)
	{
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character::Character(std::string name): name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;

}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

//---------------- Copy assignement operator ---------------
Character	&Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->name = src.getName();
		for (int i = 0; i < 4; i++)
		{
			if (src.inventory[i])
				this->inventory[i] = src.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

//--------------- Private attribute accessors --------------

std::string const &Character::getName()const
{
	return (this->name);
}

AMateria	*Character::getInventoryIdx(int idx)const
{
	if (idx < 4 && idx >= 0)
		return (this->inventory[idx]);
	return (NULL);
}

//-------------------- Action functions --------------------
void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			m = NULL;
			return ;
		}
	}
	delete m;
	m = NULL;
	std::cout << RED "Error: all inventory slots are taken!" R << std::endl;
}

void	Character::unequip(int idx)
{
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	this->inventory[idx]->use(target);
}
