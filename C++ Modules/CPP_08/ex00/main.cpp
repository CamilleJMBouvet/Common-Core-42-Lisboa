/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:04:07 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/22 15:28:53 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <ios>
#include <map>
#include <list>
#include <deque>
#include <vector>
#include <limits>
#include <csignal>
#include <climits>
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"

// -MACROS-
// Container types
#define LIST	0
#define VECTOR	1
#define DEQUE	2
// Colours
#define GREY	"\001\033[1;37m\002"
#define PINK	"\001\033[1;38;5;225m\002"
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define BLUE	"\001\033[1;38;2;147;222;255m\002"
#define RED		"\001\033[1;31m\002"
#define R			"\001\033[1;00m\002"

// TEMPLATES
template <typename Container, typename Iterator>
void	process_container(int occur, int *int_arr)
{
	Container cont;
	for (int i = 0; i < 5; i++)
		cont.push_back(int_arr[i]);

	Iterator it = easyfind(cont, occur);
	if (it != cont.end())
			std::cout << PINK << "The value " BLUE << *it << PINK " was found in the container!" << R << std::endl;
	else
		std::cout << RED << "ERROR: Element not found in container" << R << std::endl;
}

// -CLASSES
class EofException: public std::exception {};
class InvalidIntException: public std::exception {};

// -FUNCTION DEFINITIONS-
void	sigint_handler(int signal);
int		choose_container();
void	select_container_values(int *int_arr);
void	make_container(int occur, int *int_arr, int cont_type);
int		int_input(std::string type, int min, int max);
std::string user_input(std::string type);

// -FUNCTIONS-
int	main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- EASYFIND ----------------" R << std::endl;

	std::cout << GREY "Welcome! Today's goal is to find the first occurrence of an int in a container of your choice." << std::endl;
	std::cout << "Ready? Let's go!" R << std::endl << std::endl;
	int *int_arr = new int[5];

	try
	{
		int choice = choose_container();
		select_container_values(int_arr);
		make_container(int_input("n index to find", INT_MIN, INT_MAX), int_arr, choice);
	}
	catch (EofException &e)
	{
		std::cout << PINK "Leaving already? Bye" R << std::endl;
	}

	delete[] int_arr;
	return (0);
}

// Disables ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Prompts user to choose a type of container
int		choose_container()
{
	std::cout << PINK "Which container do you want to work with?" R << std::endl;
	std::string options[3] = {"list", "vector", "deque"};

	while (true)
	{
		std::string buff = user_input(" TYPE: list | vector | deque");
		for (int i = 0; i < 3; i++)
			if (!buff.compare(options[i]))
				return (i);

		std::cout << RED << "ERROR: Invalid selection, please try again" R << std::endl << std::endl;
	}
}

// Has user fills up container with 5 int values
void select_container_values(int *int_arr)
{
	std::cout << std::endl << PINK "Now, please choose 5 values to populate your container" R << std::endl;
	int i = 0;

	while (i < 5)
	{
		try
		{
			int_arr[i++] = int_input("n int value", INT_MIN, INT_MAX);
		}
		catch (InvalidIntException &e)
		{
			std::cout <<  RED "ERROR: Invalid input. Please try again!" R << std::endl;
		}
	}
}

// Sends appropriate container + iterator to container process function
void	make_container(int occur, int *int_arr, int cont_type)
{
	if (cont_type == LIST)
		process_container<std::list<int>, std::list<int>::iterator>(occur, int_arr);
	else if (cont_type == VECTOR)
		process_container<std::vector<int>, std::vector<int>::iterator>(occur, int_arr);
	else if (cont_type == DEQUE)
		process_container<std::deque<int>, std::deque<int>::iterator>(occur, int_arr);
}

// Retrieves int input from user
int	int_input(std::string type, int min, int max)
{
	std::cout << GREY "Please enter a" << type << ":" << std::endl;
	std::cout << R " > ";

	int digit;
	std::cin >> digit;
	if (std::cin.eof())
		throw (EofException());

	if (std::cin.fail() || std::cin.peek() != '\n' || digit < min || digit > max)
	{
		if (!type.compare("n index to find"))
		{
			std::cout << RED "ERROR: Invalid input." << std::endl;
			std::cout << ">> Defaulting to:" BLUE " 0" R << std::endl << std::endl;
			return (0);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw (InvalidIntException());
	}

	return (digit);
}

// Retrieves input from user
std::string	user_input(std::string type)
{
	std::cout << GREY "Please type a" << type << ":" << std::endl;
	std::cout << R " > ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (EofException());

	return (buff);
}
