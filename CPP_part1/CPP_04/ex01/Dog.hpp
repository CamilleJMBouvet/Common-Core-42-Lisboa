/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:09:08 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:35:09 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// -LIBRARIES-
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
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
