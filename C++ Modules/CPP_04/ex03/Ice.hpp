/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:05:46 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:40:15 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

// -LIBRARIES-
#include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &src);
		Ice(std::string const &type);
		virtual ~Ice(void);

		Ice	&operator=(Ice const &src);

		virtual Ice	*clone()const;
		virtual void use(ICharacter &target);
};

#endif
