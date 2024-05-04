/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:51:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 16:58:39 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <csignal>

# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define PINK		"\001\033[1;38;5;225m\002"

void	test_array(void);
void	test_instruction_sheet(void);
void	test_extra_stuff(void);
void	sigint_handler(int signal);

int	main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- Abstract Class ----------------" << std::endl;
	std::cout << R "Those tests are the same as the previous exrcise, except that we won't be instantiating any AAnimal class, as it has now become Abstract." << std::endl;
	std::cout << "Should we try, the programme wouldn't compile." << std::endl;

	while (1)
	{
		std::cout << std::endl << GREY "- | TEST 1 - Array | TEST 2 - Sheet | TEST 3 - Extra | -"  << std::endl;
		std::cout << R "> ";
		std::string buff;
		getline(std::cin, buff);
		std::cout << std::endl;
		if (!buff.compare("1"))
			test_array();
		else if (!buff.compare("2"))
			test_instruction_sheet();
		else if (!buff.compare("3"))
			test_extra_stuff();
		if (std::cin.eof())
			return (0);
	}

	return (0);
}

void	test_array(void)
{
	std::cout << BLUE "---------------- TEST 1 ----------------" R << std::endl;
	std::cout << "- Same tests as ex01, except we won't instantiate any variable of class AAnimal -> since it's now abstract" << std::endl;
	std::cout << std::endl;
	AAnimal	*arr[100];

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> 50 x \"AAnimal Default Constructor called\"" << std::endl << "-> 50 x \"Dog Default Constructor called\"" << std::endl << "-> 50 x \"Brain Default Constructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	for (int i = 0; i < 50; i++)
	{
		std::cout << PINK << i << ": " R << std::endl;
		arr[i] = new Dog();
	}
	std::cout << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> 50 x \"AAnimal Default Constructor called\"" << std::endl << "-> 50 x \"Cat Default Constructor called\"" << std::endl << "-> 50 x \"Brain Default Constructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	for (int i = 50; i < 100; i++)
	{
		std::cout << PINK << i << ": " R << std::endl;
		arr[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> 50 x \"barks\"" << std::endl << "-> 50 x \"meows\"" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << PINK << i << ": " R;
		arr[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> 50 x \"Dog Destructor called\"" << std::endl;
	std::cout << R "-> 50 x \"Cat Destructor called\"" << std::endl;
	std::cout << R "-> 100 x \"Brain Destructor called\"" << std::endl;
	std::cout << R "-> 100 x \"AAnimal Destructor called\"" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;

	for (int i = 0; i < 100; i++)
	{
		std::cout << PINK << i << ": " R << std::endl;
		delete arr[i];
	}
}

void	test_instruction_sheet(void)
{
	std::cout << BLUE "---------------- TEST 2 ----------------" R << std::endl;
	std::cout << "- Same tests as ex01, except we won't instantiate any variable of class AAnimal -> since it's now abstract" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> AAnimal Default Constructor called" << std::endl;
	std::cout << "-> AAnimal Default Constructor called" << std::endl << "-> Dog Default Constructor called" << std::endl << "-> Brain Default Constructor called" << std::endl;
	std::cout << "-> AAnimal Default Constructor called" << std::endl << "-> Cat Default Constructor called" << std::endl << "-> Brain Default Constructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	const AAnimal *dog = new Dog();
	const AAnimal *cat = new Cat();

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "Dog" << std::endl << "Cat" <<std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> AAnimal - weird noise" << std::endl << "-> Dog - barks" << std::endl << "-> Cat - meows" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl << PURPLE "EXPECTED:" << std::endl;
	std::cout << R "-> Cat Destructor called" << std::endl << "-> Brain Destructor called" << std::endl << "-> AAnimal Destructor called" << std::endl;
	std::cout << "-> Dog Destructor called" << std::endl << "-> Brain Destructor called" << std::endl << "-> AAnimal Destructor called" << std::endl;
	std::cout << "-> AAnimal Destructor called" << std::endl;
	std::cout << PURPLE "OUTPUT:" R << std::endl;
	delete cat;
	delete dog;
}

void	test_extra_stuff(void)
{
	std::cout << BLUE "---------------- TEST 3 ----------------" R << std::endl;
	std::cout << "- Same tests as ex01, except we won't instantiate any variable of class AAnimal -> since it's now abstract" << std::endl;
	std::cout << "- This test is for having fun implementing ideas into the AAnimal's brain" << std::endl;
	std::cout << "- It also allows to verify that the copy constructors/operator overloads produce deep copies!" << std::endl;
	std::cout << std::endl;

	std::cout << GREY "Let's create a" PURPLE " Dog:" R << std::endl;
	Dog *dog1 = new Dog();
	dog1->makeSound();
	std::cout << std::endl;

	std::cout << GREY "Please enter 5 ideas for the" PURPLE " Dog" GREY "'s brain:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::string idea;
		std::cout << R "> ";
		getline(std::cin, idea);
		if (std::cin.eof())
		{
			delete dog1;
			return ;
		}
		dog1->getBrain()->ideas[i] = idea;
	}
	std::cout << std::endl;

	std::cout << GREY "Now let's clone your " PURPLE "Dog!" GREY " It should have a clone brain with the same ideas." R << std::endl;
	Dog	dog2(*dog1);
	std::cout << std::endl;

	std::cout << GREY "Clone " PURPLE "Dog" GREY "'s ideas:" R << std::endl;
	for (int i = 0; dog2.getBrain()->ideas[i][0]; i++)
		std::cout << "Idea " << i << ": " << BLUE << dog2.getBrain()->ideas[i] << R << std::endl;
	dog2.makeSound();
	std::cout << std::endl;

	std::cout << GREY "Let's change the 5 ideas of our original" PURPLE " Dog" GREY "'s brain:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::string idea;
		std::cout << R "> ";
		getline(std::cin, idea);
		if (std::cin.eof())
		{
			delete dog1;
			return ;
		}
		dog1->getBrain()->ideas[i] = idea;
	}
	std::cout << std::endl;

	std::cout << GREY "We can now inject those ideas to our clone" PURPLE " Dog" GREY "'s brain by using the operator overload" R << std::endl;
	dog2 = *dog1;

	std::cout << GREY "Clone " PURPLE "Dog" GREY "'s new ideas:" R << std::endl;
	for (int i = 0; dog2.getBrain()->ideas[i][0]; i++)
		std::cout << "Idea " << i << ": " << BLUE << dog2.getBrain()->ideas[i] << R << std::endl;
	std::cout << std::endl;

	std::cout << GREY "Great! Now let's send our first " PURPLE "Dog" GREY " to \"live in a farm\"" R << std::endl;
	delete dog1;
	std::cout << BLUE ":'(" << std::endl;
	std::cout << std::endl;

	std::cout << GREY "Let's check that our clone" PURPLE " Dog" GREY " has a deep copy of the brain, and therefore still has your ideas!" R << std::endl;
	for (int i = 0; dog2.getBrain()->ideas[i][0]; i++)
		std::cout << "Idea " << i << ": " << BLUE << dog2.getBrain()->ideas[i] << R << std::endl;
	std::cout << std::endl;

	std::cout << BLUE " --- Great job! --- " R << std::endl;
}

void	sigint_handler(int signal)
{
	(void)signal;
}
