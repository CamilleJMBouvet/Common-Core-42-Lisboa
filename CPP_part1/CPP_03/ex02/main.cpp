/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:54:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:18:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <csignal>

// - TEST FUNCTIONS -
void	playtrap(ScavTrap *scavtp, FragTrap *fragtp);
void	repair(FragTrap *fragtp);
void	print_points(FragTrap *fragtp);
void 	sigintHandler(int signal);

int main(void)
{
	std::cout << PURPLE "--------------- FRAGTRAP ---------------" R << std::endl;
	std::string buff = "";

	std::cout << WHITE "Name a ClapTrap: " R "> ";
	getline(std::cin, buff);
	ClapTrap claptp(buff);
	buff = "";

	std::cout << WHITE "Name a ScavTrap: " R "> ";
	getline(std::cin, buff);
	ScavTrap scavtp(buff);
	buff = "";

	std::cout << WHITE "Name a FragTrap: " R "> ";
	getline(std::cin, buff);
	FragTrap fragtp(buff);

	playtrap(&scavtp, &fragtp);
}

void playtrap(ScavTrap *scavtp, FragTrap *fragtp)
{
	std::signal(SIGINT, sigintHandler);
	while (1)
	{
		std::string buff;
		std::cout << WHITE "\nREPAIR | ATTACK | HIGH FIVE | POINTS" R << std::endl;
		std::cout << "> ";
		std::getline(std::cin, buff);
		if (!buff.compare("REPAIR"))
			repair(fragtp);
		else if (!buff.compare("ATTACK"))
		{
			fragtp->attack(scavtp->getName());
			scavtp->takeDamage(fragtp->getAttackdmg());
		}
		else if (!buff.compare("HIGH FIVE"))
			fragtp->highFiveGuys();
		else if (!buff.compare("POINTS"))
			print_points(fragtp);
		if (std::cin.eof())
		{
			std::cout << RED "\nThat's it, I'm switching everyone off!\n" R<< std::endl;
			return ;
		}
	}
}

void	repair(FragTrap *fragtp)
{
	std::string buff;
	int pts = 0;

	std::cout << WHITE "By how many points do you want to repair?\n" R "> ";
	getline(std::cin, buff);
	pts = atoi(buff.c_str());

	if (pts > fragtp->getEnergypts())
		std::cout << PINK << fragtp->getName() \
		<< RED " doesn't have enough energy points!" R << std::endl;
	else
		fragtp->beRepaired(pts);
}

void print_points(FragTrap *fragtp)
{
	std::cout << PINK << fragtp->getName() << WHITE "'s points:" << std::endl;
	std::cout << R "Hit points: " RED << fragtp->getHitpts() << std::endl;
	std::cout << R "Energy points: " RED << fragtp->getEnergypts() << std::endl;
	std::cout << R "Attack damages: " RED << fragtp->getAttackdmg() << R << std::endl;
}

void sigintHandler(int signal)
{
	(void)signal;
}
