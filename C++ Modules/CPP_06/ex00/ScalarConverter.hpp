/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:09:00 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/08 18:41:43 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

// -LIBRARIES-
#include <iostream>
#include <climits>

// -MACROS-
# define PINK		"\001\033[1;38;5;225m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

# ifndef NULL
#  define NULL	0
# endif

// -CLASS-
class	ScalarConverter
{
	public:
		static void	convert(std::string literal);

		class IType
		{
			public:
				virtual ~IType() {};

				virtual operator char() const = 0;
				virtual operator int() const = 0;
				virtual operator float() const = 0;
				virtual operator double() const = 0;

				virtual void printTypes(std::ostream &o) const = 0;
		};
		class CharType;
		class IntType;
		class DoubleType;
		class FloatType;

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &src);
};

std::ostream &operator<<(std::ostream &o, const ScalarConverter::IType &instance);

#endif
