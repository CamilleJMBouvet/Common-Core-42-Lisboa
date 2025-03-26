/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:42:19 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:06:22 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//----------------- Macros -----------------
const int	FragTrap::HIT_PTS = 100;
const int	FragTrap::ENERGY_PTS = 100;
const int	FragTrap::ATTACK_DMG = 30;

//----------------- Constructor/Destructor -----------------
FragTrap::FragTrap(void): ClapTrap()
{
	this->hit_pts = this->HIT_PTS;
	this->energy_pts = this->ENERGY_PTS;
	this->attack_dmg = this->ATTACK_DMG;
	std::cout << "FragTrap default constructor called" R << std::endl;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called for " PINK << \
	src.getName() << R << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hit_pts = this->HIT_PTS;
	this->energy_pts = this->ENERGY_PTS;
	this->attack_dmg = this->ATTACK_DMG;
	std::cout << "FragTrap name constructor called for " PINK << name \
	<< R << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " PINK << \
	this->name << R << std::endl;
}

//---------------- Copy assignement operator ---------------
FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

//-------------------- Action functions --------------------
void	FragTrap::highFiveGuys(void)
{
	std::string five;

	std::cout << PINK << this->name \
	<< WHITE " wants a high five! Don't leave them hanging, press " RED "5 " R "\n> ";
	getline(std::cin, five);

	if (!five.compare("5"))
		std::cout << PURPLE << "~!**HELL YEAH**!~" R << std::endl;
	else
		std::cout << RED "Well done, you made " PINK << this->name << RED " cry :'(" R << std::endl;
}
