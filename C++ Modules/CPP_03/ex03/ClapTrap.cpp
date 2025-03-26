/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:39:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 19:28:59 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//----------------- Constructor/Destructor -----------------
ClapTrap::ClapTrap(void): hit_pts(10), energy_pts(10), attack_dmg(0)
{
	std::cout << "ClapTrap default constructor called" R << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src): name(src.name), hit_pts(src.hit_pts), \
energy_pts(src.energy_pts), attack_dmg(src.attack_dmg)
{
	std::cout << "ClapTrap copy constructor called for " PINK << \
	src.getName() << R << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_pts(10), energy_pts(10), attack_dmg(0)
{
	std::cout << "ClapTrap name constructor called for " PINK << name \
	<< R << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for ClapTrap " PINK << \
	this->name << R << std::endl;
}

//---------------- Copy assignement operator ---------------
ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	if (this != &src)
	{
		this->name = src.getName();
		this->hit_pts = src.getHitpts();
		this->energy_pts = src.getEnergypts();
		this->attack_dmg = src.getAttackdmg();
	}
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	ClapTrap::getName(void)const
{
	return (this->name);
}

int	ClapTrap::getHitpts(void)const
{
	return (this->hit_pts);
}

int	ClapTrap::getEnergypts(void)const
{
	return (this->energy_pts);
}

int	ClapTrap::getAttackdmg(void)const
{
	return (this->attack_dmg);
}

//-------------------- Action functions --------------------
void	ClapTrap::attack(const std::string &target)
{
	std::cout << WHITE "ClapTrap " PINK << this->name;
	if (this->energy_pts <= 0 || this->hit_pts <= 0)
	{
		std::cout << RED " is too weak to attack!" R << std::endl;
		return ;
	}

	std::cout << WHITE " attacks " PINK << target << WHITE ", causing " RED \
	<< this->attack_dmg << WHITE " points of damage" R << std::endl;

	this->energy_pts--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << PINK << this->name << WHITE " takes " RED \
	<< amount << WHITE " points of damage " << std::endl;

	this->hit_pts -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << PINK << this->name;
	if (this->energy_pts <= 0 || this->hit_pts <= 0)
	{
		std::cout << RED " is too weak to repair!" R << std::endl;
		return ;
	}

	std::cout << WHITE " is getting repaired with " RED \
	<< amount << WHITE " hit points " R << std::endl;

	this->hit_pts += amount;
	this->energy_pts--;
}
