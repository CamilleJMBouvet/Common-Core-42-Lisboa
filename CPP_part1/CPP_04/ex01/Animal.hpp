/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:06:51 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:34:23 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

// -LIBRARIES-
#include <iostream>

// -MACROS-
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREY		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

class	Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);

		Animal	&operator=(Animal const &src);

		std::string getType(void)const;

		virtual void makeSound(void)const;

	protected:
		std::string	type;
};

#endif
