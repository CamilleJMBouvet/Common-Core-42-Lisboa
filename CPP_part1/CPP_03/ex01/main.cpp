/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:45:45 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:17:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>
#include <csignal>

// - TEST FUNCTIONS -
void	playtrap(ClapTrap *claptp, ScavTrap *scavtp);
void	repair(ScavTrap *scavtp);
void	print_points(ScavTrap *scavtp);
void 	sigintHandler(int signal);

int main(void)
{
	std::cout << PURPLE "--------------- SCAVTRAP ---------------" R << std::endl;
	std::string buff = "";

	std::cout << WHITE "Name a ClapTrap: " R "> ";
	getline(std::cin, buff);
	ClapTrap claptp(buff);
	buff = "";

	std::cout << WHITE "Name a ScavTrap: " R "> ";
	getline(std::cin, buff);
	ScavTrap scavtp(buff);
	buff = "";

	playtrap(&claptp, &scavtp);
}

void	playtrap(ClapTrap *claptp, ScavTrap *scavtp)
{
	std::signal(SIGINT, sigintHandler);
	while (1)
	{
		std::string buff;
		std::cout << WHITE "\nREPAIR | ATTACK | GUARD | POINTS" R << std::endl;
		std::cout << "> ";
		std::getline(std::cin, buff);
		if (!buff.compare("REPAIR"))
			repair(scavtp);
		else if (!buff.compare("ATTACK"))
		{
			scavtp->attack(claptp->getName());
			claptp->takeDamage(scavtp->getAttackdmg());
		}
		else if (!buff.compare("GUARD"))
			scavtp->GuardGate();
		else if (!buff.compare("POINTS"))
			print_points(scavtp);
		if (std::cin.eof())
		{
			std::cout << RED "\nThat's it, I'm switching everyone off!\n" R<< std::endl;
			return ;
		}
	}
}

void	repair(ScavTrap *scavtp)
{
	std::string buff;
	int pts = 0;

	std::cout << WHITE "By how many points do you want to repair?\n" R "> ";
	getline(std::cin, buff);
	pts = atoi(buff.c_str());

	if (pts > scavtp->getEnergypts())
		std::cout << PINK << scavtp->getName() \
		<< RED " doesn't have enough energy points!" R << std::endl;
	else
		scavtp->beRepaired(pts);
}

void	print_points(ScavTrap *scavtp)
{
	std::cout << PINK << scavtp->getName() << WHITE "'s points:" << std::endl;
	std::cout << R "Hit points: " RED << scavtp->getHitpts() << std::endl;
	std::cout << R "Energy points: " RED << scavtp->getEnergypts() << std::endl;
	std::cout << R "Attack damages: " RED << scavtp->getAttackdmg() << R << std::endl;
}

void sigintHandler(int signal)
{
	(void)signal;
}
