/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:01:55 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/28 20:22:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <csignal>

// - TEST FUNCTIONS -
void	playtrap(ClapTrap *claptp, ClapTrap *claptp_1);
void	repair(ClapTrap *claptp);
void	print_points(ClapTrap *claptp);
void	cloning(ClapTrap *claptp);
void 	sigintHandler(int signal);

int main(void)
{
	std::cout << PURPLE "--------------- CLAPTRAP ---------------" R << std::endl;
	std::string buff = "";

	ClapTrap clap0;

	std::cout << WHITE "\nName a ClapTrap: " R "> ";
	getline(std::cin, buff);
	ClapTrap claptp(buff);
	buff = "";

	ClapTrap claptp_1("Ennemy");

	playtrap(&claptp, &claptp_1);
}

void	playtrap(ClapTrap *claptp, ClapTrap *claptp_1)
{
	std::signal(SIGINT, sigintHandler);
	while (1)
	{
		std::string buff;
		std::cout << WHITE "\nREPAIR | ATTACK | CLONE | POINTS" R << std::endl;
		std::cout << "> ";
		std::getline(std::cin, buff);
		if (!buff.compare("REPAIR"))
			repair(claptp);
		else if (!buff.compare("ATTACK"))
		{
			claptp->attack(claptp_1->getName());
			claptp_1->takeDamage(claptp->getAttackdmg());
		}
		else if (!buff.compare("CLONE"))
			cloning(claptp);
		else if (!buff.compare("POINTS"))
			print_points(claptp);
		if (std::cin.eof())
		{
			std::cout << RED "\nThat's it, I'm switching everyone off!\n" R<< std::endl;
			return ;
		}
	}
}

void	repair(ClapTrap *claptp)
{
	std::string buff;
	int pts = 0;

	std::cout << WHITE "By how many points do you want to repair?\n" R "> ";
	getline(std::cin, buff);
	pts = atoi(buff.c_str());

	if (pts > claptp->getEnergypts())
		std::cout << PINK << claptp->getName() \
		<< RED " doesn't have enough energy points!" R << std::endl;
	else
		claptp->beRepaired(pts);
}

void	print_points(ClapTrap *claptp)
{
	std::cout << PINK << claptp->getName() << WHITE "'s points:" << std::endl;
	std::cout << R "Hit points: " RED << claptp->getHitpts() << std::endl;
	std::cout << R "Energy points: " RED << claptp->getEnergypts() << std::endl;
	std::cout << R "Attack damages: " RED << claptp->getAttackdmg() << R << std::endl;
}

void	cloning(ClapTrap *claptp)
{
	std::cout << WHITE "Cloning in process\n" << RED "Beware! Clones don't survive long!" R << std::endl;
	ClapTrap clonetp(*claptp);

	std::cout << WHITE "New clone ";
	print_points(&clonetp);
}

void sigintHandler(int signal)
{
	(void)signal;
}
