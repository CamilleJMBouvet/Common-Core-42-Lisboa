/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:46:21 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:37:29 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

// -MACROS-
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREY		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

// -LIBRARIES-
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class	Cat: public AAnimal
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
