/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:45:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/22 16:10:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	std::string	name;
	std::cout << PINK << "> Zombie name: " R;
	std::getline(std::cin, name);

	Zombie	*new_zomb = newZombie(name);
	new_zomb->announce();
	delete new_zomb;

	std::cout << PINK << "> Chump name: " R;
	std::getline(std::cin, name);

	randomChump(name);
}
