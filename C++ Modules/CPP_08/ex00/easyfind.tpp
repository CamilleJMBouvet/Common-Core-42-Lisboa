/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:03:59 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/13 22:01:45 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "easyfind.hpp"

//----------------- Template function definition -----------------
template <typename T>
typename T::iterator	easyfind(T &container, int occur)
{
	return (std::find(container.begin(), container.end(), occur));
}
