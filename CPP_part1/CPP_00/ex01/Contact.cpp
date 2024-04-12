/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:15:00 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/12 16:28:54 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstring>
#include <iostream>
#include "Contact.hpp"

# define PINK		"\001\033[1;38;5;225m\002"
# define RED		"\001\033[0;31m\002"
# define R			"\001\033[1;00m\002"

// CONSTRUCTOR: Sets all contact fields to NULL
Contact::Contact()
{
	for (int i = 0; i < 5; i++)
		std::memset(this->_fields[i], 0, 50);
}

// Empty destroyer
Contact::~Contact(void)
{}

// Retrieves private fields
char	*Contact::get_fields(int index)
{
	return (Contact::_fields[index]);
}

// Sets private fields
bool	Contact::set_fields(int index, std::string buff)
{
	if (std::cin.eof())
		return (false);
	if (buff[0] == 0)
	{
		std::cout << RED "Error: empty string" R << std::endl;
		return (false);
	}
	if (index == 3)
		for (int i = 0; i < buff[i]; i++)
			if (!std::isdigit(buff[i]))
			{
				std::cout << "Error: entry must be numerical" << std::endl;
				return (false);
			}
	std::strncpy(Contact::_fields[index], buff.c_str(), 50);
	return (true);
}

