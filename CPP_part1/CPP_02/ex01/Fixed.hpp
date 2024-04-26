/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:33:17 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/24 17:26:03 by cbouvet          ###   ########.fr       */
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
		Fixed(int const n);
		Fixed(float const z);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=(Fixed const &other);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

		float	toFloat(void)const;
		int		toInt(void)const;

	private:

		int	_fixpt;
		static const int _fracbits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &instance);

#endif
