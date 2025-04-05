/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleType.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:21:57 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/11 20:22:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLETYPE_HPP
# define DOUBLETYPE_HPP

// -LIBRARIES-
# include "ScalarConverter.hpp"
# include "IntType.hpp"
# include <cmath>

// -CLASS-
class ScalarConverter::DoubleType: public ScalarConverter::IType
{
	public:
		DoubleType(std::string literal);
		DoubleType(ScalarConverter::DoubleType const &src);
		~DoubleType();

		double getD()const;

		static bool isDouble(std::string literal);
		void printTypes(std::ostream &o) const;

		DoubleType &operator=(ScalarConverter::DoubleType const &src);
		operator char() const;
		operator int() const;
		operator float() const;
		operator double() const;

	private:
		DoubleType();
		double _d;
};


#endif
