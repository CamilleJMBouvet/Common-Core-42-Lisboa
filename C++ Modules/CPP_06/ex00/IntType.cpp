/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:24:26 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/11 20:28:55 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntType.hpp"
#include <climits>
#include <cmath>

//----------------- Constructor/Destructor -----------------
ScalarConverter::IntType::IntType(): _i(0), _overflow(0)
{
	throw (std::exception());
}

ScalarConverter::IntType::IntType(std::string literal): _i(0), _overflow(0)
{
	if (isInt(literal) == literal.size())
	{
		long res = atol(literal.c_str());
		if (res > INT_MAX)
			this->_overflow = 1;
		if (res < INT_MIN)
			this->_overflow = -1;
		this->_i = atol(literal.c_str());
	}
	else
		throw (std::exception());
}

ScalarConverter::IntType::IntType(ScalarConverter::IntType const &src): _i(src.getI()), _overflow(src.getOverflow())
{}

ScalarConverter::IntType::~IntType()
{}

//---------------- Copy assignement operator ---------------
ScalarConverter::IntType &ScalarConverter::IntType::operator=(ScalarConverter::IntType const &src)
{
	if (this != &src)
		this->_i = src.getI();
	return (*this);
}

//--------------- Private attribute accessors --------------
int	ScalarConverter::IntType::getI()const
{
	return (this->_i);
}

int	ScalarConverter::IntType::getOverflow()const
{
	return (this->_overflow);
}

//------------------------ Overloads -----------------------
ScalarConverter::IntType::operator char() const
{
	return (static_cast<char>(this->_i));
}

ScalarConverter::IntType::operator int() const
{
	return (this->_i);
}

ScalarConverter::IntType::operator float() const
{
	return (static_cast<float>(this->_i));
}

ScalarConverter::IntType::operator double() const
{
	return (static_cast<double>(this->_i));
}

//-------------------- Action functions --------------------
size_t ScalarConverter::IntType::isInt(std::string literal)
{
	size_t i = 0;

	if (literal[0] == '+' || literal[0] == '-')
		i++;
	while (literal[i] && isdigit(literal[i]))
		i++;

	return (i);
}

void ScalarConverter::IntType::printTypes(std::ostream &o) const
{
	if (!isprint(static_cast<char>(this->_i)))
		o << "char: Non displayable" << std::endl;
	else
		o << "char: " << static_cast<char>(this->_i) << std::endl;

	if (!this->_overflow)
	{
		o << PINK "int: " << this->_i << R << std::endl;
		o << "float: " << static_cast<float>(this->_i) << ".0f" << std::endl;
		o << "double: " << static_cast<double>(this->_i) << ".0" << std::endl;
	}
	else
	{
		char sign = 0;
		if (this->_overflow < 0)
			sign = '-';
		o << PINK "int: " << sign << "overflow"  R << std::endl;
		o << "float: " << sign << "inff" << std::endl;
		o << "double: " << sign << "inf" << std::endl;
	}
}
