/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:15:32 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/16 12:07:45 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <cstring>

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define WHITE		"\001\033[1;37m\002"
# define RED		"\001\033[0;31m\002"
# define R			"\001\033[1;00m\002"

void	test_human_a(std::string buff);
void	test_human_b(std::string buff);

int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl;

	std::string	buff;
	std::cout << WHITE "Your turn!\nHumanA or HumanB? " R;
	std::getline(std::cin, buff);

	if (std::strncmp(buff.c_str(), "HumanA", 8) && std::strncmp(buff.c_str(), "HumanB", 8))
		std::cout << RED "I did not understand a word you said! Bye :'(" R << std::endl;
	else if (!std::strncmp(buff.c_str(), "HumanA", 8))
		test_human_a(buff);
	else
		test_human_b(buff);
}

void	test_human_a(std::string buff)
{
	std::cout << WHITE "> Choose a weapon: " R;
	std::getline(std::cin, buff);
	Weapon	user_weapon = Weapon(buff);

	std::cout << WHITE "> Name? " R;
	std::getline(std::cin, buff);
	if (!buff[0])
		buff = "Unknown dude";
	HumanA	user_human(buff, user_weapon);

	user_human.attack();
	std::cout << PURPLE << buff << WHITE " gave up and is taking a nap" << std::endl;

}

void	test_human_b(std::string buff)
{
	std::cout << WHITE "> Name? " R;
	std::getline(std::cin, buff);
	if (!buff[0])
		buff = "Unknown dude";
	HumanB	user_human(buff);
	user_human.attack();

	std::cout << WHITE "> Give " PURPLE << buff << WHITE " a weapon: " R;
	std::string weapon;
	std::getline(std::cin, weapon);
	Weapon	user_weapon = Weapon(weapon);

	user_human.setWeapon(user_weapon);
	user_human.attack();
	std::cout << PURPLE << buff << WHITE " gave up and is taking a nap" << std::endl;
}
