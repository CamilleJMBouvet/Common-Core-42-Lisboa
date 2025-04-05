/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatType.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:24:37 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/11 20:28:00 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatType.hpp"

//----------------- Constructor/Destructor -----------------
ScalarConverter::FloatType::FloatType(): _f(0.0f)
{
	throw (std::exception());
}

ScalarConverter::FloatType::FloatType(std::string literal): _f(0.0f)
{
	if (this->isFloat(literal))
	{
		double res = strtod(literal.c_str(), NULL);
		this->_f = static_cast<float>(res);
	}
	else
		throw (std::exception());
}

ScalarConverter::FloatType::FloatType(ScalarConverter::FloatType const &src): _f(src.getF())
{}

ScalarConverter::FloatType::~FloatType()
{}

//---------------- Copy assignement operator ---------------
ScalarConverter::FloatType &ScalarConverter::FloatType::operator=(ScalarConverter::FloatType const &src)
{
	if (this != &src)
		this->_f = src.getF();
	return (*this);
}

//--------------- Private attribute accessors --------------
float	ScalarConverter::FloatType::getF()const
{
	return (this->_f);
}

//------------------------ Overloads -----------------------
ScalarConverter::FloatType::operator char() const
{
	return (static_cast<char>(this->_f));
}

ScalarConverter::FloatType::operator int() const
{
	return (static_cast<int>(this->_f));
}

ScalarConverter::FloatType::operator float() const
{
	return (this->_f);
}

ScalarConverter::FloatType::operator double() const
{
	return (static_cast<double>(this->_f));
}

//-------------------- Action functions --------------------
bool ScalarConverter::FloatType::isFloat(std::string literal)
{
	if (!literal.compare("-inff") || !literal.compare("+inff") || !literal.compare("nanf"))
		return (true);

	if (literal[literal.size() -1] == 'f' || literal[literal.size() -1]  == 'F')
		if (ScalarConverter::DoubleType::isDouble(literal.erase(literal.size() -1)))
			return (true);

	return (false);
}

void ScalarConverter::FloatType::printTypes(std::ostream &o) const
{
	if (!isprint(static_cast<char>(this->_f)))
		o << "char: Non displayable" << std::endl;
	else
		o << "char: " << static_cast<char>(this->_f) << std::endl;

	if (static_cast<long>(this->_f) > INT_MAX || static_cast<long>(this->_f) < INT_MIN)
		o << "int: impossible" << std::endl;
	else
		o << "int: " << static_cast<int>(this->_f) << std::endl;

	float int_part_float;
	if (std::modf(static_cast<float>(this->_f), &int_part_float) == 0.0 && !isinff(this->_f))
	{
		o << PINK "float: " << static_cast<float>(this->_f) << ".0f" R << std::endl;
		o << "double: " << static_cast<double>(this->_f) << ".0" << std::endl;
	}
	else
	{
		o << PINK "float: " << static_cast<float>(this->_f) << "f" R << std::endl;
		o << "double: " << static_cast<double>(this->_f) << std::endl;
	}
}
