/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:23:03 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/22 12:10:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

// -LIBRARIES-
#include <iostream>

// -CLASS-
class Base
{
	public:
		virtual ~Base();
};

std::ostream	&operator<<(std::ostream &o, Base const &ref);

#endif
