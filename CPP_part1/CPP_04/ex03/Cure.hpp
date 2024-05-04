/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:04:02 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:40:21 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

// -LIBRARIES-
#include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &src);
		Cure(std::string const &type);
		virtual ~Cure(void);

		Cure	&operator=(Cure const &src);

		virtual Cure	*clone()const;
		virtual void 	use(ICharacter &target);
};

#endif
