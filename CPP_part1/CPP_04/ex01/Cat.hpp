/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:08:17 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:36:13 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// -LIBRARIES
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat	&operator=(Cat const &src);

		Brain	*getBrain(void)const;

		virtual void	makeSound(void)const;

	private:
		Brain	*brain;
};

#endif
