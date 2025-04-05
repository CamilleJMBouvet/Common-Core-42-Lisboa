/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:08:36 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/15 16:39:57 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

// -LIBRARIES-
# include <algorithm>
# include <iostream>
# include <stack>

// -MACROS-
// Error messages
# define ERR_FORMAT	"Invalid expression format\nPlease follow Reverse Polish Notation format"
# define ERR_CHAR	"Invalid argument\nExpected characters: numbers and operators +-/*"
# define ERR_LIMIT	"Invalid argument\nNumbers have to be lower than 10"
# define ERR_0DIV	"Division by 0 not accepted"
// Colours
# define GREEN		"\001\033[1;38;2;174;231;202m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -CLASS-
class RPN
{
	public:
		RPN(std::string expr);
		RPN(const RPN &src);
		~RPN();

		RPN	&operator=(const RPN &src);

		int getRes()const;

		int	passExpr(std::string expr);
		std::string	reFormat(std::string expr);
		void performRPN(std::stack<int> &expr_stack, char c);

	private:
		RPN();
		int _res;
};

std::ostream &operator<<(std::ostream &o, RPN &rpn);

#endif
