/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:23 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/25 21:30:07 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:

		Fixed(void);
		Fixed(int const n);
		Fixed(float const z);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=(Fixed const &instance);
		Fixed	operator+(Fixed const &nb)const;
		Fixed	operator-(Fixed const &nb)const;
		Fixed	operator*(Fixed const &nb)const;
		Fixed	operator/(Fixed const &nb)const;

		bool 	operator>(Fixed const &instance);
		bool	operator<(Fixed const &instance);
		bool	operator>=(Fixed const &instance);
		bool	operator<=(Fixed const &instance);
		bool	operator==(Fixed const &instance);
		bool	operator!=(Fixed const &instance);

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

		float	toFloat(void)const;
		int		toInt(void)const;

		static Fixed		&min(Fixed &nb1, Fixed &nb2);
		static Fixed const	&min(Fixed const &nb1, Fixed const &nb2);
		static Fixed		&max(Fixed &nb1, Fixed &nb2);
		static Fixed const	&max(Fixed const &nb1, Fixed const &nb2);

	private:

		int _fixpt;
		static const int _fracbits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &instance);

#endif
