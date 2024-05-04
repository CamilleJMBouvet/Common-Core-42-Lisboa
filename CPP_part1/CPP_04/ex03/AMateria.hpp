/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:57:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:46:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// -LIBRARIES-
#include <iostream>
#include "ICharacter.hpp"

// -MACROS-
# define GREY		"\001\033[1;37m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define R			"\001\033[1;00m\002"

class	ICharacter;

class	AMateria
{
	public:
		AMateria(void);
		AMateria(AMateria const &src);
		AMateria(std::string const &type);
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria const &src);

		std::string const &getType()const;

		virtual AMateria *clone()const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string	type;
};

#endif
