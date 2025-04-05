/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:55:19 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/22 16:24:05 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <iostream>
#include "PmergeMe.hpp"

// -MACROS-
// NULL
#ifndef NULL
# define NULL	0
#endif
// Errors
#define ERR_ARGS	"Invalid number of arguments\nExpected: ./[programme] [integer] [integer] [...]"
#define ERR_FORMAT	"Invalid format\nExpected: space-separated positive integer sequence"
#define ERR_DUPLICATE	"Invalid sequence\nDuplicate values are not accepted"
// Colours
#define GREY	"\001\033[1;37m\002"
#define PHIL	"\001\033[0m\002\t\001\033[1m\002"
#define PINK	"\001\033[1;38;5;225m\002"
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define BLUE	"\001\033[1;38;2;147;222;255m\002"
#define GREEN	"\001\033[1;38;2;174;231;202m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

// -FUNCTION DEFINITION-
void	print_explanation();
int		*check_format(int ac, char **av);
void	print_output(PmergeMe *merges, int ac, int *unsorted);

// -FUNCTIONS-
int	main(int ac, char **av)
{
	std::cout << PURPLE "---------------- PmergeMe ----------------" R << std::endl;

	print_explanation();
	int *unsorted = NULL;

	try
	{
		if (ac < 2 || !av[1][0])
			throw (std::runtime_error(ERR_ARGS));

		unsorted = check_format(ac, &av[1]);

		PmergeMe merges[3] = {
			PmergeMe(ac -1, unsorted, std::queue<int>()),
			PmergeMe(ac -1, unsorted, std::vector<int>()),
			PmergeMe(ac -1, unsorted, std::set<int>())
		};

		print_output(merges, ac, unsorted);
	}
	catch (std::exception &e)
	{
		std::cout << RED "ERROR: " << e.what() << R << std::endl;
	}
	
	if (unsorted)
		delete[] unsorted;
}

void	print_explanation()
{
	std::cout << GREY "Let's compare how different containers perform with the Ford Johnson Merge Insertion algorithm." << std::endl;
	std::cout << std::endl << GREY "The containers I chose for this exercise are:" R << std::endl;

	std::cout << GREY " > " PINK "std::vector" GREY " - for its efficiency: " << std::endl;
	std::cout << "   It's a dynamically allocated contiguous array => its elements are adjacent in memory;" << std::endl;
	std::cout << "   This makes operations significantly faster (merging, inserting, swapping, sorting)." R << std::endl;

	std::cout << GREY " > " PINK "std::queue" GREY " - for its lack of flexibility: " << std::endl;
	std::cout << "   It's a FIFO container => it doesn't support iterators, and access is only possible at the front and back;" << std::endl;
	std::cout << "   It stores data in separate memory chunks => making lookup slowers" R << std::endl << std::endl;
}

// Checks if arg format is respected
int	*check_format(int ac, char **av)
{
	int *unsorted = new int[ac -1];

	std::set<std::string> dupcheck_set(av, av + (ac -1));
	if (dupcheck_set.size() != static_cast<size_t>(ac -1))
	{
		delete[] unsorted;
		throw (std::runtime_error(ERR_DUPLICATE));
	}

	for (int i = 0; i < ac -1; i++)
	{
		std::string nb = av[i];
		if (!nb[0] || nb.find_first_not_of("0123456789") != nb.npos || nb.size() > 10)
		{
			delete[] unsorted;
			throw (std::runtime_error(ERR_FORMAT));
		}
		double res = strtod(av[i], 0);
		if (res > INT_MAX)
		{
			delete[] unsorted;
			throw (std::runtime_error(ERR_FORMAT));
		}
		unsorted[i] = static_cast<int>(res);
	}
	return (unsorted);
}

// Prints output of operations
void	print_output(PmergeMe *merges, int ac, int *unsorted)
{
	std::cout << BLUE "Before:	" GREY;
	for (int i = 0; i < ac -1; i++)
		std::cout << unsorted[i] << " ";
	std::cout << R << std::endl;

	std::cout << BLUE "After:	" GREY;
	merges[1].printSorted();
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
		merges[i].printTime();
}
/*
 - TEST
 - CHECK FOR LEAKS*/
