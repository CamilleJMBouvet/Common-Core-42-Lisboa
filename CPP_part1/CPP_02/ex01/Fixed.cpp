/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:12:32 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/26 14:56:21 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors/Destructors
Fixed::Fixed(void): _fixpt(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src): _fixpt(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const n): _fixpt(roundf(n * pow(2, _fracbits)))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const z): _fixpt(roundf(z * pow(2, _fracbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Private attribute accessors
int	Fixed::getRawBits(void)const
{
	return (this->_fixpt);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixpt = raw;
}

// Subject-specific Member-functions
float Fixed::toFloat(void)const
{
	return (ldexp(this->_fixpt, -this->_fracbits));
}

int Fixed::toInt(void)const
{
	return (roundf(this->toFloat()));
}

// Operator overloads
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixpt = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &instance)
{
	o << instance.toFloat();
	return (o);
}

