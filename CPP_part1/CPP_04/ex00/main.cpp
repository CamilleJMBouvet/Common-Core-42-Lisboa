/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:00:10 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:49:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <csignal>
#include <cstdlib>

# define PURPLE		"\001\033[1;38;2;209;174;231m\002"

void	test_stack_instance(void);
void	test_dynamic_instance(void);
void	test_wrong_anim(void);
void	sigint_handler(int signal);

int	main()
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- Polymorphism ----------------" << std::endl;

	while (1)
	{
		std::cout << std::endl << GREY "- | TEST 1 - Stack Instance | TEST 2 - Dynamic Instance | - TEST 3 - Wrong Animals"  << std::endl;
		std::cout << R "> ";
		std::string buff;
		getline(std::cin, buff);
		std::cout << std::endl;
		if (!buff.compare("1"))
			test_stack_instance();
		else if (!buff.compare("2"))
			test_dynamic_instance();
		else if (!buff.compare("3"))
			test_wrong_anim();
		if (std::cin.eof())
			return (0);
	}

	return (0);
}

void	test_stack_instance(void)
{
	std::cout << BLUE "---------------- TEST 1 ----------------" R << std::endl;
	std::cout << "- Tests whether each class behaves normally upon stack instantiation" << std::endl << std::endl;

	std::cout << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> Animal Default Constructor called" << std::endl;
	std::cout << "-> Animal Default Constructor called" << std::endl;
	std::cout << "-> Dog Default Constructor called" << std::endl;
	std::cout << "-> Animal Default Constructor called" << std::endl;
	std::cout << "-> Cat Default Constructor called" << std::endl;

	std::cout << PURPLE "OUTPUT:" R << std::endl;
	Animal anim;
	Dog dog;
	Cat cat;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "Dog" << std::endl << "Cat" << std::endl << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	std::cout << dog.getType() << " " << std::endl;
	std::cout << cat.getType() << " " << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> Animal - weird noise" << std::endl << "-> Dog - barks" << std::endl << "-> Cat - meows" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	anim.makeSound();
	dog.makeSound();
	cat.makeSound();

	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> Cat Destructor called" << std::endl << "-> Animal Destructor called" << std::endl;
	std::cout << "-> Dog Destructor called" << std::endl << "-> Animal Destructor called" << std::endl;
	std::cout << "-> Animal Destructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
}

void	test_dynamic_instance(void)
{
	std::cout << BLUE "---------------- TEST 2 ----------------" R << std::endl;
	std::cout << "- Instruction sheet test." << std::endl << "- Tests whether each class behaves normally upon dynamic instantiation via its base class" << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> Animal Default Constructor called" << std::endl;
	std::cout << "-> Animal Default Constructor called" << std::endl << "-> Dog Default Constructor called" << std::endl;
	std::cout << "-> Animal Default Constructor called" << std::endl << "-> Cat Default Constructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	const Animal *anim = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "Dog" << std::endl << "Cat" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> Animal - weird noise" << std::endl << "-> Dog - barks" << std::endl << "-> Cat - meows" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	anim->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> Cat Destructor called" << std::endl << "-> Animal Destructor called" << std::endl;
	std::cout << "-> Dog Destructor called" << std::endl << "-> Animal Destructor called" << std::endl;
	std::cout << "-> Animal Destructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	delete cat;
	delete dog;
	delete anim;
}

void	test_wrong_anim(void)
{
	std::cout << BLUE "---------------- TEST 3 ----------------" R << std::endl;
	std::cout << "- Shows what occurs when a function isn't declared as virtual in the base class" << std::endl;

	std::cout << std::endl << "Let's create a WrongCat with class WrongCat" << std::endl;
	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> WrongAnimal Default Constructor called" << std::endl << "-> WrongCat Default Constructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	const WrongCat *wcat = new WrongCat();

	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> WrongCat - meows" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	wcat->makeSound();

	std::cout << std::endl << "Let's create a WrongCat with class WrongAnimal" << std::endl;
	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> WrongAnimal Default Constructor called" << std::endl << "-> WrongCat Default Constructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	const WrongAnimal *wcat2 = new WrongCat();

	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> WrongCat - moohs" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	wcat2->makeSound();

	std::cout << std::endl << PURPLE "EXPECTED:" R << std::endl;
	std::cout << "-> WrongCat Destructor called" << std::endl << "-> WrongAnimal Destructor called" << std::endl;
	std::cout << "-> WrongCat Destructor called" << std::endl << "-> WrongAnimal Destructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	delete wcat;
	delete wcat2;

}

void	sigint_handler(int signal)
{
	(void)signal;
}
