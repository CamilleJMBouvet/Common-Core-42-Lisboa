/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:10:12 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/04 16:52:38 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <csignal>
#include <cstdlib>

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define HERO_ICE	1
# define HERO_CURE	2
# define HERO_NONE	0

// -FUNCTIONS-
void		test_instruction_sheet(void);
void		my_awesome_test(void);
std::string	name_me(std::string person);
void 		delete_all(IMateriaSource *library, ICharacter *norm, ICharacter *hero, ICharacter *comp);
int			pick_spell(IMateriaSource *library, ICharacter *hero, ICharacter *comp);
int			time_to_fight(ICharacter *norm, Character *hero, Character *comp);
void		get_reward(IMateriaSource *library, Character *hero);
void		sigint_handler(int signal);

int	main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- Interface & recap ----------------" << std::endl;

	while (1)
	{
		std::cout << std::endl << GREY "- | TEST 1 - Sheet | TEST 2 - My Awesome test | -" << std::endl;
		std::cout << R "> ";
		std::string buff;
		getline(std::cin, buff);
		std::cout << std::endl;
		if (!buff.compare("1"))
			test_instruction_sheet();
		else if (!buff.compare("2"))
			my_awesome_test();
		if (std::cin.eof())
			return (0);
	}

	return (0);
}

void	test_instruction_sheet(void)
{
	std::cout << BLUE "---------------- TEST 1 ----------------" R << std::endl;
	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> * shoots an ice bolt at bob *" << std::endl << "-> * heals bob's wounds *" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	my_awesome_test(void)
{
	std::cout << BLUE "---------------- TEST 2 ----------------" R << std::endl;
	std::cout << "- An interactive version to explore how the classes work together" << std::endl;

	ICharacter *norm = new Character("Norminette");
	std::string heroname = name_me("hero");
	if (heroname[0] == -1)
	{
		delete_all(NULL, norm, NULL, NULL);
		return;
	}
	ICharacter *hero = new Character(heroname);
	std::cout << std::endl;

	std::string compname = name_me("companion");
	if (compname[0] == -1)
	{
		delete_all(NULL, norm, hero, NULL);
		return ;
	}
	ICharacter *comp = new Character(compname);
	std::cout << std::endl;

	std::cout << BLUE "Welcome, " PURPLE << hero->getName() << BLUE " and " << PURPLE << comp->getName() << BLUE "!" << std::endl;
	std::cout << "You are on a quest to defeat the almighty " RED << norm->getName() << BLUE " by the power vested in C++" << std::endl;
	std::cout << "Let the quest begin!" R << std::endl << std::endl;

	IMateriaSource *library = new MateriaSource();
	library->learnMateria(new Ice());
	library->learnMateria(new Cure());
	std::cout << GREY "Okay, " PURPLE << hero->getName() << GREY ", there are 2 books of spells on the library in front of you." << std::endl;
	if (!pick_spell(library, hero, comp))
	{
		delete_all(library, norm, hero, comp);
		return ;
	}
	if (time_to_fight(norm, dynamic_cast<Character*>(hero), dynamic_cast<Character*>(comp)))
		get_reward(library, dynamic_cast<Character*>(hero));
	delete_all(library, norm, hero, comp);
	return ;
}

void	delete_all(IMateriaSource *library, ICharacter *norm, ICharacter *hero, ICharacter *comp)
{
	if (library)
		delete library;
	if (norm)
		delete norm;
	if (hero)
		delete hero;
	if (comp)
		delete comp;
}

std::string	name_me(std::string person)
{
	std::cout << GREY "Choose a " << person << " name:" << std::endl;
	std::cout << R "> ";
	std::string buff;
	getline(std::cin, buff);
	std::cout << std::endl;
	if (std::cin.eof())
		buff[0] = -1;
	return (buff);
}

int	pick_spell(IMateriaSource *library, ICharacter *hero, ICharacter *comp)
{
	AMateria *ice_book = library->createMateria("ice");
	AMateria *cure_book = library->createMateria("cure");

	std::cout << GREY "Which book do you want to pick? " << std::endl;
	std::cout << std::endl << GREY "1 - Ice spell book | 2 - Cure spell book" << std::endl;
	std::cout << R "> ";
	std::string buff;
	getline(std::cin, buff);
	std::cout << std::endl;
	if (std::cin.eof())
	{
		delete ice_book;
		delete cure_book;
		return (0);
	}

	if (!buff.compare("1"))
	{
		std::cout << GREY "The Ice spell book is yours, " PURPLE << hero->getName() << GREY "!" R << std::endl;
		hero->equip(ice_book);
		ice_book = NULL;
	}
	else if (!buff.compare("2"))
	{
		std::cout << GREY "The Cure spell book is yours, " PURPLE << hero->getName() << GREY "!" R << std::endl;
		hero->equip(cure_book);
		cure_book = NULL;
	}
	if (ice_book)
	{
		std::cout << PURPLE << comp->getName() << GREY " picked the Ice spell book!" R << std::endl;
		comp->equip(ice_book);
	}
	if (cure_book)
	{
		std::cout << PURPLE << comp->getName() << GREY " picked the Cure spell book!" R << std::endl;
		comp->equip(cure_book);
	}
	return (1);
}

int	time_to_fight(ICharacter *norm, Character *hero, Character *comp)
{
	std::cout << std::endl << GREY "Oh my, " RED << norm->getName() << GREY " has just spat a beam of " RED "Misaligned variable declaration" GREY " on ";
	std::string buff;

	if (hero->getInventoryIdx(0) && !hero->getInventoryIdx(0)->getType().compare("cure"))
	{
		std::cout << comp->getName() << "!" << std::endl;
		std::cout << "Quick, use your Cure spell to save them! Just type 1" << std::endl;
		std::cout << R "> ";
		getline(std::cin, buff);
		std::cout << std::endl;
		if (buff.compare("1"))
		{
			std::cout << GREY "How could you let " << PURPLE << comp->getName() << GREY " die?" << std::endl;
			std::cout << std::endl << RED "---------------- GAME OVER: YOU LOOSE ----------------" R << std::endl;
			return (0);
		}
		if (std::cin.eof())
			return (0);
		hero->use(0, *comp);
	}
	else
	{
		std::cout << "you!" << std::endl;
		std::cout << "Do not fear, for your faithful companion "  PURPLE << comp->getName() << GREY " has got your back!" << std::endl;
		std::cout << PURPLE << comp->getName() << GREY ": ";
		if (comp->getInventoryIdx(0) && !comp->getInventoryIdx(0)->getType().compare("cure"))
			comp->use(0, *hero);
		else if (comp->getInventoryIdx(1) && !comp->getInventoryIdx(1)->getType().compare("cure"))
			comp->use(1, *hero);
	}

	buff = "";
	std::cout << std::endl << RED << norm->getName() << GREY " is about to strike again with " RED "Missing tab for indent level" GREY "!" << std::endl;
	std::cout << "Now has come the time to fight back!" << std::endl;
	if (hero->getInventoryIdx(0) && !hero->getInventoryIdx(0)->getType().compare("ice"))
	{
		std::cout << GREY "Use your Ice spell! Type 1" << std::endl;
		std::cout << R "> ";
		getline(std::cin, buff);
		std::cout << std::endl;
		if (buff.compare("1"))
		{
			std::cout << GREY "You fool!" << std::endl;
			std::cout << std::endl << RED "---------------- GAME OVER: YOU LOOSE ----------------" R << std::endl;
			return (0);
		}
		if (std::cin.eof())
			return (0);
		hero->use(0, *norm);
	}
	else
	{
		std::cout << PURPLE << comp->getName() << GREY ": ";
		comp->use(0, *norm);
	}

	std::cout << std::endl;
	return (1);
}

void	get_reward(IMateriaSource *library, Character *hero)
{
	std::cout << GREY "YOU DID IT! You defeated " RED "Norminette" GREY " !" << std::endl;
	std::cout << "Enjoy your reward an unlimited supply of spellbooks (As long as they fit in your backpack, of course)." << std::endl;
	while (1)
	{
		std::cout << std::endl << GREY "1 - Ice spell book | 2 - Cure spell book | 3 - Unequip | -"<< std::endl;
		std::cout << R "> ";
		std::string buff;
		getline(std::cin, buff);
		std::cout << std::endl;
		if (!buff.compare("1"))
		{
			library->learnMateria(new Ice());
			AMateria *ice_book = library->createMateria("ice");
			std::cout << GREY "The Ice spell book is yours, " PURPLE << hero->getName() << GREY "!" R << std::endl;
			hero->equip(ice_book);
		}
		else if (!buff.compare("2"))
		{
			library->learnMateria(new Cure());
			AMateria *cure_book = library->createMateria("cure");
			std::cout << GREY "The Cure spell book is yours, " PURPLE << hero->getName() << GREY "!" R << std::endl;
			hero->equip(cure_book);

		}
		else if (!buff.compare("3"))
		{
			std::cout << GREY "Type index to unequip (0-3): "<< std::endl;
			std::cout << R "> ";
			std::string idx;
			getline(std::cin, idx);
			std::cout << std::endl;
			AMateria *trash = hero->getInventoryIdx(atoi(idx.c_str()));
			if (!trash)
				std::cout << GREY "Nothing to unequip!" R << std::endl;
			else
			{
				hero->unequip(atoi(idx.c_str()));
				delete trash;
			}
		}
		if (std::cin.eof())
		{
			std::cout << std::endl << BLUE "---------------- GAME OVER: YOU WIN ----------------" R << std::endl;
			return ;
		}
	}
}

void	sigint_handler(int signal)
{
	(void)signal;
}
