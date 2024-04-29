/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:36:19 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:23:54 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

// -LIBRARIES-
#include <iostream>

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define WHITE		"\001\033[1;37m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const &src);
		ClapTrap(std::string name);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &src);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void)const;
		int			getHitpts(void)const;
		int			getEnergypts(void)const;
		int			getAttackdmg(void)const;

	protected:
		std::string name;
		int	hit_pts;
		int	energy_pts;
		int	attack_dmg;

};
#endif
