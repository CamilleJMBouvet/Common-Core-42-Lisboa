/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:35:09 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/22 15:37:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include <ctime>
#include <limits>
#include <csignal>
#include <ios>
#include "Span.hpp"

// -MACROS-
#define GREY	"\001\033[1;37m\002"
#define PINK	"\001\033[1;38;5;225m\002"
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define BLUE	"\001\033[1;38;2;147;222;255m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

// -CLASS-
class EofException: public std::exception
{};
class InvalidIntException: public std::exception
{};

// -FUNCTION DEFINITIONS-
void	sigint_handler(int signal);
void	subject_example();
void	test_small_vector();
void	test_massive_vector();
int		random_int();
long	long_input(std::string type, long min, long max);
std::string user_input(std::string type);

// -FUNCTIONS-
int main(void)
{
	//std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- span ----------------" R << std::endl;
	
	std::cout << GREY "Welcome! Now we'll be creating a vector, and checking the largest and shortest span between two entries." R << std::endl;
	std::cout << PINK "Let's go!" R << std::endl << std::endl;
	try
	{
		subject_example();
		test_small_vector();
		test_massive_vector();
	}
	catch (EofException &e)
	{
		std::cout << PINK "Leaving already? Bye" R << std::endl;
	}
}

// Disables ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Replicates the example given in the subject
void	subject_example()
{
	std::cout << PINK "Let's start with the example from the instruction sheet." \
	"The output should be the same:" R << std::endl;

	Span sp = Span(6);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

// Generates + populates a small-sized vector with user input + checks if bounds are respected
void	test_small_vector()
{
	std::cout << std::endl << PINK "Now, you'll get to create a vector with your own 5 values." << std::endl;
	std::cout << "The goal here is to confirm that the shortest and longest spans are correct." R << std::endl;

	Span sp(5);
	for (int i = 0; i < 5;)
	{
		try
		{
			sp.addNumber(static_cast<int>(long_input("n int", INT_MIN, INT_MAX)));
			i++;
			if (i == 5)
			{
				std::cout << PINK "Great, now let's make sure we can't a randomized int, since we've reached our max intended vector size." R << std::endl;
				sp.addNumber(random_int());
			}
		}
		catch (InvalidIntException &e)
		{
			std::cout <<  RED "ERROR: Invalid input. Please try again!" R << std::endl;
		}
		catch (Span::MaxCapacityException &e)
		{
			std::cerr << RED "ERROR: " << e.what() << R << std::endl << std::endl;
			break ;
		}
	}
	
	try
	{
		std::cout << GREY "The shortest span is:\n" BLUE << sp.shortestSpan() << std::endl;
		std::cout << GREY "The longest span is:\n" BLUE << sp.longestSpan() << R << std::endl;
	}
	catch (Span::EmptySpanException &e)
	{
		std::cerr << RED "ERROR: " << e.what() << R << std::endl << std::endl;
	}
}

// Tests mass-generation of vector entries
void	test_massive_vector()
{
	std::cout << std::endl << PINK "For this last test, you can choose the size of the vector" << std::endl;
	std::cout << "Go ahead, but stay within the bounds of an unsigned int, and be mindful of the PC's resources!" R << std::endl;
	std::srand(std::time(0));
	
	do
	{	
		try
		{
			Span sp(static_cast<int>(long_input(" vector size", 0, UINT_MAX)));
			std::generate_n(std::back_inserter(sp.access_vct()), sp.get_n(), random_int);
	
			std::cout << std::endl << GREY "You've created a vector of size " BLUE << sp.access_vct().size() << std::endl;
			std::cout << GREY "The shortest span is:\n" BLUE << sp.shortestSpan() << std::endl;
			std::cout << GREY "The longest span is:\n" BLUE << sp.longestSpan() << R << std::endl << std::endl;
			return ;
		}
		catch (InvalidIntException &e)
		{
			std::cout <<  RED "ERROR: Invalid input. Please try again!" R << std::endl;
		}
		catch (Span::SpanException &e)
		{
			std::cerr << RED "ERROR: " << e.what() << R << std::endl << std::endl;
		}
	} while (true);
}

// Returns a random int out of long_max
int	random_int()
{
	int val = rand() % INT_MAX;
	if (!rand() % 2)
		val *= -1;
		
	return (val);
}

// Retrieves digit from user
long		long_input(std::string type, long min, long max)
{
	std::cout << GREY "Please enter a" << type << ":" << std::endl;
	std::cout << R " > ";

	long digit;
	std::cin >> digit;

	if (std::cin.eof())
		throw (EofException());

	if (std::cin.fail() || std::cin.peek() != '\n' || digit < min || digit > max)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw (InvalidIntException());
	}

	return (digit);
}


