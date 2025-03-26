/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:45:12 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:22:49 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <cstdlib>
#include <csignal>

// - TEST FUNCTIONS -
void	playtrap(DiamondTrap *dmdtp, ClapTrap *claptp);
void	repair(DiamondTrap *dmdtp);
void	print_points(DiamondTrap *dmdtp);
void 	sigintHandler(int signal);

int main(void)
{
	std::cout << PURPLE "--------------- DIAMONDTRAP ---------------" R << std::endl;
	std::string buff = "";

	std::cout << WHITE "Name a ClapTrap: " R "> ";
	getline(std::cin, buff);
	ClapTrap claptp(buff);
	buff = "";

	std::cout << WHITE "Name a DiamondTrap: " R "> ";
	getline(std::cin, buff);
	DiamondTrap dmdtp(buff);
	buff = "";

	playtrap(&dmdtp, &claptp);
}

void playtrap(DiamondTrap *dmdtp, ClapTrap *claptp)
{
	std::signal(SIGINT, sigintHandler);
	while (1)
	{
		std::string buff;
		std::cout << WHITE "\nREPAIR | ATTACK | GUARD | HIGH FIVE | WHO | POINTS" R << std::endl;
		std::cout << "> ";
		std::getline(std::cin, buff);
		if (!buff.compare("REPAIR"))
			repair(dmdtp);
		else if (!buff.compare("ATTACK"))
		{
			dmdtp->attack(claptp->getName());
			claptp->takeDamage(dmdtp->getAttackdmg());
		}
		else if (!buff.compare("GUARD"))
			dmdtp->GuardGate();
		else if (!buff.compare("HIGH FIVE"))
			dmdtp->highFiveGuys();
		else if (!buff.compare("WHO"))
			dmdtp->WhoAmI();
		else if (!buff.compare("POINTS"))
			print_points(dmdtp);
		if (std::cin.eof())
		{
			std::cout << RED "\nThat's it, I'm switching everyone off!\n" R<< std::endl;
			return ;
		}
	}
}

void	repair(DiamondTrap *dmdtp)
{
	std::string buff;
	int pts = 0;

	std::cout << WHITE "By how many points do you want to repair?\n" R "> ";
	getline(std::cin, buff);
	pts = atoi(buff.c_str());

	if (pts > dmdtp->getEnergypts())
		std::cout << PINK << dmdtp->getName() \
		<< RED " doesn't have enough energy points!" R << std::endl;
	else
		dmdtp->beRepaired(pts);
}

void print_points(DiamondTrap *dmdtp)
{
	std::cout << PINK << dmdtp->getName() << WHITE "'s points:" << std::endl;
	std::cout << R "Hit points: " RED << dmdtp->getHitpts() << std::endl;
	std::cout << R "Energy points: " RED << dmdtp->getEnergypts() << std::endl;
	std::cout << R "Attack damages: " RED << dmdtp->getAttackdmg() << R << std::endl;
}

void sigintHandler(int signal)
{
	(void)signal;
}
