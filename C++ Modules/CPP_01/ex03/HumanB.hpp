/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:15:18 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/15 17:49:10 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	public:

		HumanB(std::string name);
		~HumanB(){}


		void	attack(void);
		void	setWeapon(Weapon &weapon);

	private:

		std::string	name;
		Weapon		*weapon;
};

#endif

