/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:00:31 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:40:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

// -LIBRARIES-
#include "IMateriaSource.hpp"
#include <iostream>

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &src);

		virtual void			learnMateria(AMateria *);
		virtual AMateria 		*createMateria(std::string const &type);

		AMateria	*stored[4];
};

#endif
