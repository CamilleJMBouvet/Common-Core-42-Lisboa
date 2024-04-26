/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:20:38 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/23 19:22:37 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed
{
	public:

		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=(Fixed const &other);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

	private:

		int	_fixpt;
		static const int _fracbits = 8;
};

#endif
