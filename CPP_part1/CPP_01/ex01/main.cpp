/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:16:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/16 12:07:27 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	int	horde_nb;

	std::cout << PURPLE "How many zombies in the horde? " R;
	std::cin >> horde_nb;

	if (horde_nb <= 0)
	{
		std::cout << RED "Not enough zombies!" R << std::endl;
		return (1);
	}
	if (horde_nb > 15)
	{
		std::cout << RED "Are you sure? You will have to name them all!"
		WHITE "\nType 'Y' to continue: " R;
		std::string buff;
		while (1)
			if (std::getline(std::cin, buff) && buff[0])
				break ;
		if (std::strncmp(buff.c_str(), "Y", 1))
		{
			std::cout << WHITE "Goodbye :'(" R << std::endl;
			return (1);
		}
	}

	Zombie *horde = zombieHorde(horde_nb, "send");
	for (int i = 0; i < horde_nb; i++)
		horde[i].announce();

	std::cout << std::endl;
	delete[] horde;

	return (0);
}
