/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:10 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/22 12:10:40 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

// -LIBRARIES-
#include <iostream>

// -DATA STRUCT-
struct Data
{
	std::string	title;
	std::string	artist;
	std::string	album;
	int			year;
};

std::ostream	&operator<<(std::ostream &o, Data const &data_struct);

#endif
