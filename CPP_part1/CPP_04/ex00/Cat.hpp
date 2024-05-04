/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:07:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/30 16:42:55 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// -LIBRARIES-
#include "Animal.hpp"
#include <iostream>

class Cat: public Animal
{
	public:

		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat	&operator=(Cat const &src);

		virtual void	makeSound(void)const;
};

#endif
