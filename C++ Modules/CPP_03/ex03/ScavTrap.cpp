/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:40:12 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 19:40:08 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//----------------- Macros -----------------
const int	ScavTrap::HIT_PTS = 100;
const int	ScavTrap::ENERGY_PTS = 50;
const int	ScavTrap::ATTACK_DMG = 20;

//----------------- Constructor/Destructor -----------------
ScavTrap::ScavTrap(void): ClapTrap()
{
	this->hit_pts = this->HIT_PTS;
	this->energy_pts = this->ENERGY_PTS;
	this->attack_dmg = this->ATTACK_DMG;
	std::cout << "ScavTrap default constructor called" R << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called for " PINK << \
	src.getName() << R << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hit_pts = this->HIT_PTS;
	this->energy_pts = this->ENERGY_PTS;
	this->attack_dmg = this->ATTACK_DMG;
	std::cout << "ScavTrap name constructor called for " PINK << name \
	<< R << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called for ScavTrap " PINK << \
	this->name << R << std::endl;
}

//---------------- Copy assignement operator ---------------
ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

//-------------------- Action functions --------------------
void	ScavTrap::GuardGate(void)
{
	std::cout << PINK << this->name << WHITE " is now in Gate keeper mode" R \
	<< std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << WHITE "ScavTrap " PINK << this->name;
	if (this->energy_pts <= 0 || this->hit_pts <= 0)
	{
		std::cout << RED " is too weak to attack!" R << std::endl;
		return ;
	}

	std::cout << WHITE " attacks " PINK << target << WHITE ", causing " RED \
	<< this->attack_dmg << WHITE " points of damage" R << std::endl;

	this->energy_pts--;
}
