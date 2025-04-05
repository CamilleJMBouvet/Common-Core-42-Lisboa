/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:59:48 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/15 15:26:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// -FUNCTION DEFINITION-
template <typename T>
void	iter(T *arr, int len, void (*f)(T &))
{
	if (!arr)
		return ;

	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif
