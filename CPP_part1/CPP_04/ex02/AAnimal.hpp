/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:06:51 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/01 18:12:26 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

// -LIBRARIES-
#include <iostream>

// -MACROS-
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREY		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);

		AAnimal	&operator=(AAnimal const &src);

		std::string getType(void)const;

		virtual void makeSound(void)const = 0;

	protected:
		std::string	type;
};

#endif
