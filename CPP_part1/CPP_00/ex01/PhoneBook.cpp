/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:44:01 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/12 16:29:50 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "awesome_phonebook.hpp"

// CONSTRUCTOR - empty
PhoneBook::PhoneBook(void)
{}

// DESTRUCTOR - empty
PhoneBook::~PhoneBook(void)
{}

// Uses index to add new contacts to phonebook
bool	PhoneBook::add(Contact new_contact, int i)
{
	if (!new_contact.get_fields(0))
	{
		std::cout << RED "Error: empty entry" << std::endl;
		return (false);
	}
	this->indexes[i] = new_contact;
	return (true);
}

// Displays phonebook's contacts
void	PhoneBook::search(void)
{
	char	buff[11];

	for (int i = 0; i < 8; i++)
	{
		std::cout << PINK << std::setw(10) << i+1;
		for (int j = 0; j < 3; j++)
		{
			std::cout << PURPLE "|" R;
			std::memset(buff, 0, 11);
			strncpy(buff, this->indexes[i].get_fields(j), 10);
			if (buff[9])
				buff[9] = '.';
			std::cout << std::setw(10) << buff ;
		}
		std::cout << std::endl;
	}
	return ;
}

// Displays selected indexed contact's info
void	PhoneBook::select_index(void)
{
	int			index;
	std::string	buff;

	buff[0] = 0;
	std::cout << WHITE "\n Please Select Index " << std::endl << R "> ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
		return ;
	for (int i = 0; buff[i]; i++)
		if (!std::isdigit(buff[i]))
		{
			std::cout << RED "Error: entry must be numerical" R << std::endl;
			this->select_index();
			return ;
		}
	index = std::atoi(buff.c_str());
	if (index < 1 || index > 8)
	{
		std::cout << RED "Error: incorrect index" R << std::endl;
		this->select_index();
		return;
	}
	for (int i = 0; i < 5; i++)
		std::cout << PINK << this->indexes[index -1].msg[i] << R << this->indexes[index -1].get_fields(i) << std::endl;
}

// Exits
void	PhoneBook::exit(void)
{
	std::cout << BLUE "\n Goodbye :'(" R << std::endl;
	std::cout << PINK "---------------------------------" R << std::endl;
	return ;
}
