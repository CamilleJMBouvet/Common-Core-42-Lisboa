/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:34:13 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/22 16:10:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{}

Zombie::~Zombie(void)
{
	std::cout << WHITE << this->name << " destroyed" R \
	<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout << WHITE << this->name << \
	 ": BraiiiiiiinnnzzzZ..." R << std::endl;
}

