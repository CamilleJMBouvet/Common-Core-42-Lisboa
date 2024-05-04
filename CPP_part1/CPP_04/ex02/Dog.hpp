/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:41:11 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:37:38 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// -MACROS-
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREY		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

// -LIBRARIES-
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public AAnimal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog	&operator=(Dog const &src);

		Brain	*getBrain(void)const;

		virtual void	makeSound(void)const;

	private:
		Brain	*brain;
};

#endif
