/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:45:01 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:25:08 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//----------------- Constructor/Destructor -----------------
DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->energy_pts = ScavTrap::ENERGY_PTS;
	std::cout << "DiamondTrap default constructor called" R << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap copy constructor called for " PINK << \
	src.FragTrap::getName() << R << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->energy_pts = ScavTrap::ENERGY_PTS;
	this->DiamondTrap::name = name;
	std::cout << "DiamondTrap name constructor called for " PINK << name \
	<< R << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called for DiamondTrap " PINK << \
	this->name << R << std::endl;
}

//---------------- Copy assignement operator ---------------
DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
{
	if (this != &src)
		FragTrap::operator=(src);
	return (*this);
}

//-------------------- Action functions --------------------
void	DiamondTrap::WhoAmI(void)
{
	std::cout << BLUE "-\"My name is " PINK << DiamondTrap::name << BLUE \
	", but my ClapTrap name is " PINK << ClapTrap::name << BLUE "\"-" R << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
