/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:16:40 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/08 18:43:49 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "CharType.hpp"
#include "IntType.hpp"
#include "DoubleType.hpp"
#include "FloatType.hpp"

//----------------- Constructor/Destructor -----------------
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{}

//---------------- Copy assignement operator ---------------
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return (*this);
}

//-------------------- Action functions --------------------
void	ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
	{
		std::cout << RED "String is empty" R << std::endl;
		return ;
	}

	try
	{
		ScalarConverter::IType	*scal;
		if (ScalarConverter::CharType::isChar(literal))
			scal = new ScalarConverter::CharType(literal);
		else if (ScalarConverter::IntType::isInt(literal) == literal.size())
			scal = new ScalarConverter::IntType(literal);
		else if (ScalarConverter::DoubleType::isDouble(literal))
			scal = new ScalarConverter::DoubleType(literal);
		else if (ScalarConverter::FloatType::isFloat(literal))
			scal = new ScalarConverter::FloatType(literal);
		else
		{
			std::cout << RED "String does not represent any recognisable literal" R << std::endl;
			return ;
		}
		std::cout << *scal;
		delete scal;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: IType subclass instantiation misuse" R << std::endl;
	}
}

//--------------- Stream Operator Overload -----------------
std::ostream &operator<<(std::ostream &o, const ScalarConverter::IType &instance)
{
	instance.printTypes(o);
	return (o);
}
