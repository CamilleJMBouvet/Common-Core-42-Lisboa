/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:23:05 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/11 21:02:05 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharType.hpp"

//----------------- Constructor/Destructor -----------------
ScalarConverter::CharType::CharType(): _c(0)
{
	throw (std::exception());
}

ScalarConverter::CharType::CharType(std::string literal): _c(0)
{
	if (this->isChar(literal))
		this->_c = literal[0];
	else
		throw (std::exception());
}

ScalarConverter::CharType::CharType(ScalarConverter::CharType const &src): _c(src.getC())
{}

ScalarConverter::CharType::~CharType()
{}

//---------------- Copy assignement operator ---------------
ScalarConverter::CharType &ScalarConverter::CharType::operator=(ScalarConverter::CharType const &src)
{
	if (this != &src)
		this->_c = src.getC();
	return (*this);
}

//--------------- Private attribute accessors --------------
char	ScalarConverter::CharType::getC()const
{
	return (this->_c);
}

//------------------------ Overloads -----------------------
ScalarConverter::CharType::operator char() const
{
	return (this->_c);
}

ScalarConverter::CharType::operator int() const
{
	return (static_cast<int>(this->_c));
}

ScalarConverter::CharType::operator float() const
{
	return (static_cast<float>(this->_c));
}

ScalarConverter::CharType::operator double() const
{
	return (static_cast<double>(this->_c));
}

//-------------------- Action functions --------------------
bool ScalarConverter::CharType::isChar(std::string literal)
{
	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (true);
	return (false);
}

void ScalarConverter::CharType::printTypes(std::ostream &o) const
{
	o << PINK "char: " << this->_c << R << std::endl;
	o << "int: " << static_cast<int>(this->_c) << std::endl;
	o << "float: " << static_cast<float>(this->_c) << ".0f" << std::endl;
	o << "double: " << static_cast<double>(this->_c) << ".0" << std::endl;
}
