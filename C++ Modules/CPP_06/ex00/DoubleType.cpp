/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleType.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:25:01 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/13 23:20:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoubleType.hpp"

//----------------- Constructor/Destructor -----------------
ScalarConverter::DoubleType::DoubleType(): _d(0.0)
{
	throw (std::exception());
}

ScalarConverter::DoubleType::DoubleType(std::string literal): _d(0.0)
{
	if (this->isDouble(literal))
		this->_d = strtod(literal.c_str(), NULL);
	else
		throw (std::exception());
}

ScalarConverter::DoubleType::DoubleType(ScalarConverter::DoubleType const &src): _d(src.getD())
{}

ScalarConverter::DoubleType::~DoubleType()
{}

//---------------- Copy assignement operator ---------------
ScalarConverter::DoubleType &ScalarConverter::DoubleType::operator=(ScalarConverter::DoubleType const &src)
{
	if (this != &src)
		this->_d = src.getD();
	return (*this);
}

//--------------- Private attribute accessors --------------
double	ScalarConverter::DoubleType::getD()const
{
	return (this->_d);
}

//------------------------ Overloads -----------------------
ScalarConverter::DoubleType::operator char() const
{
	return (static_cast<char>(this->_d));
}

ScalarConverter::DoubleType::operator int() const
{
	return (static_cast<int>(this->_d));
}

ScalarConverter::DoubleType::operator float() const
{
	return (static_cast<float>(this->_d));
}

ScalarConverter::DoubleType::operator double() const
{
	return (this->_d);
}

//-------------------- Action functions --------------------
bool ScalarConverter::DoubleType::isDouble(std::string literal)
{
	if (!literal.compare("-inf") || !literal.compare("+inf") || !literal.compare("nan"))
		return (true);

	size_t	cut = ScalarConverter::IntType::isInt(literal);
	if (literal[cut] == '.' && literal[cut +1] && (ScalarConverter::IntType::isInt(&literal[cut +1]) == literal.size() -(cut +1)))
		return (true);

	return (false);
}

void ScalarConverter::DoubleType::printTypes(std::ostream &o) const
{
	if (!isprint(static_cast<char>(this->_d)))
		o << "char: Non displayable" << std::endl;
	else
		o << "char: " << static_cast<char>(this->_d) << std::endl;

	if (static_cast<long>(this->_d) > INT_MAX || static_cast<long>(this->_d) < INT_MIN)
		o << "int: impossible" << std::endl;
	else
		o << "int: " << static_cast<int>(this->_d) << std::endl;

	double int_part_double;
	if (std::modf(static_cast<double>(this->_d), &int_part_double) == 0.0 && !isinff(this->_d))
	{
		o << "float: " << static_cast<float>(this->_d) << ".0f" << std::endl;
		o << PINK "double: " << static_cast<double>(this->_d) << ".0"  R << std::endl;
	}
	else
	{
		o << "float: " << static_cast<float>(this->_d) << "f" << std::endl;
		o << PINK "double: " << static_cast<double>(this->_d) << R << std::endl;
	}
}
