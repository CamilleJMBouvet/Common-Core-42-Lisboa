/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:47:50 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/27 19:38:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const &src);
		ScavTrap(std::string name);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &src);

		void		GuardGate(void);
		virtual void attack(const std::string &target);

	private:
		static const int	HIT_PTS;
		static const int	ENERGY_PTS;
		static const int	ATTACK_DMG;
};

#endif
