/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:15:24 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/15 18:00:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define WHITE		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{}

void	HumanA::attack()
{
	std::cout << PURPLE << this->name << WHITE << " attacks with " BLUE \
	<< this->weapon.getType() << R << std::endl;
}
