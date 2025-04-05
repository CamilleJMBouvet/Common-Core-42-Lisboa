/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:13:58 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/10 18:48:40 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "RPN.hpp"

//----------------- Constructor/Destructor -----------------
RPN::RPN()
{
	throw (std::runtime_error("Forbidden constructor"));
}

RPN::RPN(std::string expr): _res(passExpr(expr))
{}

RPN::RPN(const RPN &src): _res(src.getRes())
{}

RPN::~RPN()
{}

//---------------- Copy assignement operator ---------------
RPN	&RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->_res = src.getRes();
	return (*this);
}

//--------------- Private attribute accessors --------------
int RPN::getRes()const
{
	return (this->_res);
}

//-------------------- Action functions --------------------
int	RPN::passExpr(std::string expr)
{
	expr = reFormat(expr);
	std::stack<int> expr_stack;
	std::string ops = "-+*/";

	for (int i = 0; expr[i]; i++)
	{
		if (isdigit(expr[i]))
			expr_stack.push(expr[i] - '0');
		else if (ops.find(expr[i]) != ops.npos)
		{
			if (expr_stack.size() < 2)
				throw (std::runtime_error(ERR_FORMAT));
			this->performRPN(expr_stack, expr[i]);
		}
		else
			throw (std::runtime_error(ERR_FORMAT));
	}

	if (expr_stack.size() != 1)
		throw (std::runtime_error(ERR_FORMAT));

	return (expr_stack.top());
}

std::string	RPN::reFormat(std::string expr)
{
	if (expr.empty() || expr.find_first_not_of("0123456789 /*-+") != expr.npos)
			throw (std::runtime_error(ERR_CHAR));

	for (int i = 0; expr[i]; i++)
	{
		if (isdigit(expr[i]))
		{
			if (!expr[i +1])
				throw (std::runtime_error(ERR_FORMAT));
			else if (expr[i +1] && isdigit(expr[i +1]))
				throw (std::runtime_error(ERR_LIMIT));
		}
		else if (!i && expr[i] != ' ')
			throw (std::runtime_error(ERR_FORMAT));
	}

	expr.erase(std::remove(expr.begin(), expr.end(), ' '), expr.end());

	return (expr);
}

void		RPN::performRPN(std::stack<int> &expr_stack, char c)
{
	int op2 = expr_stack.top();
	expr_stack.pop();
	if (!op2)
		throw (std::runtime_error(ERR_0DIV));

	int op1 = expr_stack.top();
	expr_stack.pop();

	if (c == '+')
		expr_stack.push(op1 + op2);
	else if (c == '-')
		expr_stack.push(op1 - op2);
	else if (c == '*')
		expr_stack.push(op1 * op2);
	else if (c == '/')
		expr_stack.push(op1 / op2);
}

//----------------- Nested class functions -----------------
//--------------- Stream Operator Overload -----------------
std::ostream &operator<<(std::ostream &o, RPN &rpn)
{
	return (o << rpn.getRes());
}
