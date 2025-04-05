/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:16:56 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/22 10:36:12 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

// -LIBRARIES-
# include <stdint.h>
# include "data_struct.hpp"

// -CLASS-
class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &src);
		~Serializer();

		Serializer	&operator=(Serializer const &src);
};

#endif
