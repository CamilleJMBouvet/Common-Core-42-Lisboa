/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/26 20:21:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//-------------- Constructors/Destructors --------------
Fixed::Fixed(void): _fixpt(0)
{}

Fixed::Fixed(int const n): _fixpt(roundf(n * pow(2, _fracbits)))
{}

Fixed::Fixed(float const z): _fixpt(roundf(z * pow(2, _fracbits)))
{}

Fixed::Fixed(Fixed const &src): _fixpt(src.getRawBits())
{}

Fixed::~Fixed(void)
{}

//------------ Arithmetic Operator Overload ------------
Fixed	&Fixed::operator=(Fixed const &instance)
{
	this->_fixpt = instance.getRawBits();
	return(*this);
}

Fixed	Fixed::operator+(Fixed const &nb)const
{
	return (Fixed(this->toFloat() + nb.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &nb)const
{
	return (Fixed(this->toFloat() - nb.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &nb)const
{
	return (Fixed(this->toFloat() * nb.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &nb)const
{
	return (Fixed(this->toFloat() / nb.toFloat()));
}

//------------ Comparison Operator Overload ------------
bool	Fixed::operator>(Fixed const &instance)
{
	if (this->toFloat() > instance.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &instance)
{
	if (this->toFloat() < instance.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &instance)
{
	if (this->toFloat() >= instance.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &instance)
{
	if (this->toFloat() <= instance.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &instance)
{
	if (this->toFloat() == instance.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &instance)
{
	if (this->toFloat() != instance.toFloat())
		return (true);
	return (false);
}

//------------ Incr/Decr Operator Overload -------------
Fixed	Fixed::operator++(void)
{
	this->_fixpt++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixpt++;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->_fixpt--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixpt--;
	return (tmp);
}

//------------- Stream Operator Overload ---------------
std::ostream	&operator<<(std::ostream &o, const Fixed &instance)
{
	o << instance.toFloat();
	return (o);
}

//------------ Private attribute accessors -------------
int	Fixed::getRawBits(void)const
{
	return(this->_fixpt);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixpt = raw;
}

//---------------- Conversion functions ----------------
float Fixed::toFloat(void)const
{
	return (ldexp(this->_fixpt, -this->_fracbits));
}

int Fixed::toInt(void)const
{
	return (roundf(this->toFloat()));
}

//------------------ Max/Min Overload ------------------
Fixed	&Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

Fixed const	&Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1.toFloat() < nb2.toFloat())
		return (nb1);
	return (nb2);
}

Fixed	&Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

Fixed const	&Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
	if (nb1.toFloat() > nb2.toFloat())
		return (nb1);
	return (nb2);
}
