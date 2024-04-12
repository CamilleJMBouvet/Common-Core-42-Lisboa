/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:25:05 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/12 16:27:12 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awesome_phonebook.hpp"

int	main()
{
	int			inst;
	std::string	buff;
	PhoneBook	phonebook;

	inst = 0;
	std::cout << PINK "------------ WELCOME ------------" R << std::endl;
	buff[0] = 0;
	while (1)
	{
		std::cout << WHITE "\n ~ Please Select Command: ~ " R << std::endl;
		std::cout << PURPLE " >ADD       >SEARCH       >EXIT" R << std::endl;
		std::cout << "\n> ";
		std::getline(std::cin, buff);
		if (!std::strncmp(buff.c_str(), "ADD", std::strlen(buff.c_str()) +1))
		{
			phonebook.add(create_contact(), inst);
			inst++;
			if (inst > 7)
				inst -= 8;
		}
		else if (!std::strncmp(buff.c_str(), "SEARCH", std::strlen(buff.c_str()) +1))
		{
			phonebook.search();
			phonebook.select_index();
		}
		if (std::cin.eof() || (buff[0] && !std::strncmp(buff.c_str(), "EXIT", std::strlen(buff.c_str()) +1)))
		{
			phonebook.exit();
			return (0);
		}
	}
}

// Fill contact fields
Contact	create_contact()
{
	std::string	buff;
	Contact	new_contact;

	buff[0] = 0;
	for (int i = 0; i < 5; i++)
	{
		while (!new_contact.get_fields(i)[0])
		{
			std::cout << PINK " - Contact's " << new_contact.msg[i] << "" R;
			std::getline(std::cin, buff);
			new_contact.set_fields(i, buff);
			if (std::cin.eof())
				return (new_contact);
		}
	}
	std::cout << std::endl;

	return (new_contact);
}
