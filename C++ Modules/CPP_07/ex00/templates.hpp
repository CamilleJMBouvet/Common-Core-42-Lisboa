/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:01:48 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/30 23:51:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

// -FUNCTION DEFINITION-
template <typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const	&min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T const	&max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
