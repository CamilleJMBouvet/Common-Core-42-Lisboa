/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:19:21 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/11 21:07:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTTYPE_HPP
# define INTTYPE_HPP

// -LIBRARIES-
# include "ScalarConverter.hpp"

// -CLASS-
class ScalarConverter::IntType: public ScalarConverter::IType
{
	public:
		IntType(std::string literal);
		IntType(ScalarConverter::IntType const &src);
		~IntType();

		int	getI()const;
		int	getOverflow()const;

		static size_t isInt(std::string literal);
		void printTypes(std::ostream &o) const;

		IntType &operator=(ScalarConverter::IntType const &src);
		operator char() const;
		operator int() const;
		operator float() const;
		operator double() const;

	private:
		IntType();
		int	_i;
		int	_overflow;
};

#endif
