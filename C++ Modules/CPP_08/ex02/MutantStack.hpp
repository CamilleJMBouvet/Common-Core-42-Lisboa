/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:28:00 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/19 21:42:30 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

// -LIBRARIES-
# include <stack>
# include <deque>

// -CLASS-
template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		MutantStack();
		MutantStack(MutantStack<T> const &src);
		~MutantStack();

		MutantStack<T> &operator=(MutantStack<T> const &src);

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};

# include "MutantStack.tpp"

#endif
