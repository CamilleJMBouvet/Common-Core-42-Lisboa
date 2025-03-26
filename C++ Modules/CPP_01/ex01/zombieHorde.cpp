/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:16:56 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/16 12:07:38 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*horde = new Zombie[N];
	std::string	names[N];

	for (int i = 0; i < N; i++)
	{
		std::cout << PINK << "Zombie #" << i+1 << ": " R;
		std::string	buff;
		while (1)
			if (std::getline(std::cin, buff) && buff[0] != 0)
				break ;
		horde[i].set_name(buff);
	}
	std::cout << std::endl;
	return (horde);
}
