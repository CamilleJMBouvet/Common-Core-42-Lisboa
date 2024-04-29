/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:53:23 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:04:29 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

// -LIBRARIES-
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(FragTrap const &src);
		FragTrap(std::string name);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &src);

		void		highFiveGuys(void);

	private:
		static const int	HIT_PTS;
		static const int	ENERGY_PTS;
		static const int	ATTACK_DMG;
};

#endif
