/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:21:06 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/11 20:21:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATTYPE_HPP
# define FLOATTYPE_HPP

// -LIBRARIES-
# include "ScalarConverter.hpp"
# include "DoubleType.hpp"

// -CLASS-
class ScalarConverter::FloatType: public ScalarConverter::IType
{
	public:
		FloatType(std::string literal);
		FloatType(ScalarConverter::FloatType const &src);
		~FloatType();

		float getF()const;

		static bool isFloat(std::string literal);
		void printTypes(std::ostream &o) const;

		FloatType &operator=(ScalarConverter::FloatType const &src);
		operator char() const;
		operator int() const;
		operator float() const;
		operator double() const;

	private:
		FloatType();
		float _f;
};

#endif
