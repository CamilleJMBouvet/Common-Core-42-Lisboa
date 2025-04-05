/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:12 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/22 10:36:23 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Serializer.hpp"

//----------------- Constructor/Destructor -----------------
Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &src)
{
	(void)src;
}

Serializer::~Serializer()
{}

//---------------- Copy assignement operator ---------------
Serializer	&Serializer::operator=(Serializer const &src)
{
	(void)src;
	return (*this);
}

//-------------------- Action functions --------------------
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

