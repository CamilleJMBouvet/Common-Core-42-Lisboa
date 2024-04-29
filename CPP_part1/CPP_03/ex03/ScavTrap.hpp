/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:38:12 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 19:35:34 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

// -LIBRARIES
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(ScavTrap const &src);
		ScavTrap(std::string name);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &src);

		void		GuardGate(void);
		virtual void attack(const std::string &target);

	protected:
		static const int	HIT_PTS;
		static const int	ENERGY_PTS;
		static const int	ATTACK_DMG;
};

#endif
