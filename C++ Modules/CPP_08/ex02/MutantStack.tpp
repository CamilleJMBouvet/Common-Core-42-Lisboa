/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:28:02 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/19 21:41:43 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//----------------- Constructor/Destructor -----------------
template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src)
{
	this->c = src.c;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

//---------------- Copy assignement operator ---------------
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src)
{
	if (*this != src)
		this->c = src.c;
	return (*this);
}

//-------------------- Action functions --------------------
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}
