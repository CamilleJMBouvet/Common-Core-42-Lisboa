/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:57:24 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/11 23:34:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

// -LIBRARIES-
#include <iostream>

// -MACROS-
# ifndef NULL
#  define NULL	0
# endif

// -CLASS-
class OutOfBoundsException: public std::exception
{
	public:
		virtual const char *what()const throw();
};

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array	&operator=(Array const &src);
		T		&operator[](unsigned int index);
		T const	&operator[](unsigned int index)const;

		unsigned int size()const;

	private:
		T *_arr;
		unsigned int _size;
};


# include "Array.tpp"

#endif
