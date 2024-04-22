/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:15:21 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/15 17:34:07 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_name)
{
	if (!weapon_name[0])
		this->type = "air";
	else
		this->type = weapon_name;
}

const std::string	Weapon::getType()
{
	return(this->type);
}

void	Weapon::setType(std::string new_string)
{
	if (!new_string[0])
		this->type = "air";
	this->type = new_string;
}

