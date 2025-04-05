/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:00:36 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/15 15:30:21 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <cstdlib>
#include <climits>
#include <csignal>
#include <iostream>
#include "templates.hpp"

// -MACROS-
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -FUNCTION DEFINITION-
void		sigint_handler(int signal);
void		my_test(void);
void		instruction_test(void);
void		convert_type(std::string type);
bool		check_char(std::string str);
double		check_int_double(std::string type, int dflag);
std::string	user_input(std::string type);

// -FUNCTION-
int	main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- SwapMinMax ----------------" R << std::endl << std::endl;

	std::cout << GREY "I've created template functions that can be used with any data type - or even classes." << std::endl;
	std::cout << "First, let's see if the output is the same as in the project's instructions:"  R << std::endl << std::endl;
	instruction_test();

	std::cout << std::endl << GREY "All correct, but how " RED "boring" GREY " was that huh?" << std::endl;
	std::cout << "Let's " PINK "spice things up" GREY " a little!" << std::endl << std::endl;
	try
	{
		my_test();
	}
	catch (std::exception &e)
	{
		std::cout << PINK "Leaving already? Bye!" R << std::endl;
		return (1);
	}

	return (0);
}

// Disable ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Executes tests featured in the subject sheet
void	instruction_test(void)
{
	int a = 2;
	int b = 3;

	::swap(a,b);
	std::cout << "	a = " << a << ", b = " << b << std::endl;
	std::cout << "	min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "	max(a, b) = " << ::max(a, b) << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "	c = " << c << ", d = " << d << std::endl;
	std::cout << "	min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "	max(c, d) = " << ::max(c, d) << std::endl << std::endl ;
}

// Option menu asking user for type to try
void	my_test(void)
{
	std::cout << PINK "What type do you want to try?" << std::endl;
	std::string buff;
	std::string options[4] = {"char", "int", "double", "string"};

	while (true)
	{
		std::cout << GREY "TYPE: char | int | double | string" << std::endl;
		std::cout << R " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw(std::exception());

		for (int i = 0; i < 4; i++)
			if (!options[i].compare(buff))
				return (convert_type(buff));

		std::cout << RED << "invalid selection, please try again" R << std::endl << std::endl;
	}
}

// Retrieves user input for each variable + executes the template functions for the chosen type
void	convert_type(std::string type)
{
	if (!type.compare("int"))
	{
		int	a = static_cast<int>(check_int_double(type + " a", 0));
		int b = static_cast<int>(check_int_double(type + " b", 0));
		
		::swap(a,b);
		std::cout << PINK "	a = " << a << ", b = " << b << std::endl;
		std::cout << "	min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "	max(a, b) = " << ::max(a, b) << R << std::endl << std::endl;
	}
	else if (!type.compare("double"))
	{
		double a = check_int_double(type + " a", 1);
		double b = check_int_double(type + " b", 1);

		::swap(a,b);
		std::cout << PINK "	a = " << a << ", b = " << b << std::endl;
		std::cout << "	min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "	max(a, b) = " << ::max(a, b) << R << std::endl << std::endl;
	}
	else
	{
		std::string a = user_input(type + " a");
		std::string b = user_input(type + " b");

		if (!type.compare("char") && (!check_char(a) || !check_char(b)))
			std::cout << RED "Incorrect char! Input will be treated as a string." R << std::endl;

		::swap(a,b);
		std::cout << PINK "	a = " << a << ", b = " << b << std::endl;
		std::cout << "	min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "	max(a, b) = " << ::max(a, b) << R << std::endl << std::endl;
	}
}

// Checks if variable complies with the definition of a char
bool	check_char(std::string str)
{
	if (str.size() == 1 && isprint(str[0]))
		return (true);
	return (false);
}

// Checks if variable complies with the definition of an int or double
double	check_int_double(std::string type, int dflag)
{
	while (true)
	{
		std::string input = user_input(type);

		int sign = 0;
		if (input[0] == '-' || input[0] == '+')
			sign++;

		size_t stop = input.find_first_not_of("0123456789", sign);
		if (dflag && input[stop] == '.')
			if (input[stop +1] && input.find_first_not_of("0123456789", stop +1) == input.npos)
				stop = input.npos;
				
		if (stop == input.npos)
		{
			try
			{
				double res = strtod(input.c_str(), NULL);
				if (dflag || (!dflag && res <= INT_MAX && res >= INT_MIN))
					return (res);
			}
			catch (std::exception &e)
			{}
		}
		std::cout << RED "Invalid input! Please try again." R << std::endl;
	}
}

// Retrieves user input
std::string	user_input(std::string type)
{
	std::cout << GREY "Please choose a " << type << ":" << std::endl;
	std::cout << R " > ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (std::exception());

	return (buff);
} 
