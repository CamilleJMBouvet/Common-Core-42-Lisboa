/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:16:13 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/15 16:25:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstring>
#include <string>

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define WHITE		"\001\033[1;37m\002"
# define RED		"\001\033[0;31m\002"
# define R			"\001\033[1;00m\002"

class Zombie
{
	public:
		Zombie(){};
		~Zombie(void);

		void	announce(void);
		void	set_name(std::string name);

	private:
		std::string	name;
};

#endif
