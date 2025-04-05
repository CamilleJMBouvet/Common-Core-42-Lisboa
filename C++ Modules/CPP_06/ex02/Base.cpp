/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:23:19 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/22 12:10:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Base.hpp"

//----------------- Constructor/Destructor -----------------
Base::~Base()
{}

//--------------- Stream Operator Overload -----------------
std::ostream	&operator<<(std::ostream &o, Base const &ref)
{
	return (o << &ref);
}
