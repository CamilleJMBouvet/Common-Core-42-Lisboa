/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:35:18 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/15 20:25:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Span.hpp"

//----------------- Constructor/Destructor -----------------
Span::Span(): _n(0)
{}

Span::Span(unsigned int n): _n(n)
{
	this->_vct.reserve(n);
}

Span::Span(Span const &src): _n(src.get_n()), _vct(src.get_vct())
{}

Span::~Span()
{}

//---------------- Copy assignement operator ---------------
Span	&Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_n = src.get_n();
		this->_vct = src.get_vct();
	}
	return (*this);
}

//--------------- Private attribute accessors --------------
unsigned int	Span::get_n()const
{
	return (this->_n);
}

std::vector<int>	Span::get_vct()const
{
	return (this->_vct);
}

std::vector<int> &Span::access_vct()
{
	return (this->_vct);
}

//-------------------- Action functions --------------------
void	Span::addNumber(int nb)
{
	if (this->_vct.size() < this->_n)
		this->_vct.push_back(nb);
	else
		throw (MaxCapacityException());
}

int	Span::shortestSpan()
{
	if (this->_vct.size() < 2)
		throw (EmptySpanException());

	int diff = INT_MAX;
	std::sort(this->_vct.begin(), this->_vct.end());

	for (unsigned int i = 0; i < this->_vct.size() -1; i++)
	{
		int newdiff = this->_vct[i +1] - this->_vct[i];
		if (newdiff < diff)
			diff = newdiff;
	}

	return (diff);
}

int	Span::longestSpan()
{
	if (this->_vct.size() < 2)
		throw (EmptySpanException());

	return (*max_element(this->_vct.begin(), this->_vct.end()) \
	- *min_element(this->_vct.begin(), this->_vct.end()));
}

//----------------- Nested class functions -----------------
char const	*Span::MaxCapacityException::what()const throw()
{
	return ("Reached vector's max capacity");
}

char const	*Span::EmptySpanException::what()const throw()
{
	return ("Span doesn't have enough elements for processing comparisons");
}
