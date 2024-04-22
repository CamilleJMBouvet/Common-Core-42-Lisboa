/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:15:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/15 17:50:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define WHITE		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

HumanB::HumanB(std::string name): name(name)
{
	this->weapon = NULL;
}

void	HumanB::attack()
{
	if (!this->weapon)
		std::cout << PURPLE << this->name << WHITE << " attacks with" BLUE \
		<< " his bare hands"<< R << std::endl;
	else
		std::cout << PURPLE << this->name << WHITE << " attacks with " BLUE \
		<< this->weapon->getType() << R << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	if (!weapon.getType()[0])
		return ;
	this->weapon = &weapon;
}
