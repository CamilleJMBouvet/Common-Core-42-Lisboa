/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:38:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:24:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

// -MACROS-
# define GREEN		"\001\033[1;38;2;174;231;202m\002"
# define GREY		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

// -Libraries-
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal(void);

		WrongAnimal	&operator=(WrongAnimal const &src);

		std::string	getWrongType(void)const;

		void	makeSound(void)const;

	protected:
		std::string wrong_type;
};

#endif
