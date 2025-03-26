/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:07:32 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:46:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHARACTER_HPP
# define CHARACTER_HPP

// -LIBRARIES-
#include "ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character(void);
		Character(Character const &src);
		Character(std::string name);
		virtual ~Character(void);

		Character	&operator=(Character const &src);

		virtual std::string const &getName()const;

		virtual void		equip(AMateria *m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter &target);

		virtual AMateria	*getInventoryIdx(int idx)const;

	private:
		std::string	name;
		AMateria	*inventory[4];
};

#endif
