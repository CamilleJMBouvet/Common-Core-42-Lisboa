/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:57:59 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/15 15:28:23 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Array.hpp"

//----------------- Constructor/Destructor -----------------
template <typename T>
Array<T>::Array(): _arr(NULL), _size(0)
{}
template <typename T>
Array<T>::Array(unsigned int n): _arr(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(Array const &src): _size(src.size())
{
	this->_arr = new T[src.size()]();
	for (unsigned int i = 0; i < src.size(); i++)
		this->_arr[i] = src[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->_arr)
		delete[] this->_arr;
}

//---------------- Operator overloads---------------
template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
	if (*this != src)
	{
		this->_size = src.size();
		if (this->_arr)
			delete[] this->_arr;
		this->_arr = new T[src.size()]();
		for (unsigned int i = 0; i < src.size(); i++)
			this->_arr[i] = src[i];
	}
	return (*this);
}

//--------------- Private attribute accessors --------------
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (OutOfBoundsException());
	return (this->_arr[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index)const
{
	if (index >= this->_size)
		throw (OutOfBoundsException());
	return (this->_arr[index]);
}

template <typename T>
unsigned int Array<T>::size()const
{
	return (this->_size);
}

//----------------- Other class functions -----------------
char const *OutOfBoundsException::what()const throw()
{
	return ("Index is out of bounds");
}
//--------------- Stream Operator Overload -----------------
