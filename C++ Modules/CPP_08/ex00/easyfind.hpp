/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:03:41 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/13 22:01:42 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// -LIBRARIES-
#include <algorithm>

// -TEMPLATE-
template <typename T>
typename T::iterator	easyfind(T &container, int occur);

# include "easyfind.tpp"

#endif
