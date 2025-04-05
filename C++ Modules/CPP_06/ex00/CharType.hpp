/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharType.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:15:17 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/13 23:14:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARTYPE_HPP
# define CHARTYPE_HPP

// -LIBRARIES-
# include "ScalarConverter.hpp"

// -CLASS-
class ScalarConverter::CharType: public ScalarConverter::IType
{
	public:
		CharType(std::string literal);
		CharType(ScalarConverter::CharType const &src);
		~CharType();

		char getC()const;

		static bool isChar(std::string literal);
		void printTypes(std::ostream &o) const;

		CharType &operator=(ScalarConverter::CharType const &src);
		operator char() const;
		operator int() const;
		operator float() const;
		operator double() const;

	private:
		CharType();
		char _c;
};

#endif
