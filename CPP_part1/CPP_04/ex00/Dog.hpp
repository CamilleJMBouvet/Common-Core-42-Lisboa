/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:26 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/30 14:16:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

// -LIBRARIES-
#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{
	public:

		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Dog	&operator=(Dog const &src);

		void	makeSound(void)const;
};

#endif
