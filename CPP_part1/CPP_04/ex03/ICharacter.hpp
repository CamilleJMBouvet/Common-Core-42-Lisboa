/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:56:36 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:46:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

// -LIBRARIES
#include "AMateria.hpp"

//-MACROS-
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

class AMateria;

class	ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual std::string const &getName()const = 0;

		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif
