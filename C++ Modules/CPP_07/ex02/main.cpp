/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:55:49 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/15 15:34:41 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include <csignal>
#include <climits>
#include "Array.hpp"

// -MACROS-
//-Data types-
#define CHAR	0
#define INT		1
#define DOUBLE	2
#define STRING	3
//-Output colours-
#define GREY	"\001\033[1;37m\002"
#define PINK	"\001\033[1;38;5;225m\002"
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define BLUE	"\001\033[1;38;2;147;222;255m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

// -CLASSES-
class EofException: public std::exception
{};

// -FUNCTION DEFINITION-
void	sigint_handler(int signal);
int		choose_type();
int		choose_index(int code);
void 	make_arr(int type, int size);
void 	arr_input(Array<std::string> &arr, int type);
int		check_type(std::string str, int type);
std::string	user_input(std::string type);

// -FUNCTIONS-
int	main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- ARRAY ----------------" R << std::endl << std::endl;

	std::cout << GREY "Hello again! Now, I've created a template class Array, " \
	"which will behave like - you guessed it - an array. " \
	"You'll be able to access/edit its indexed values with " PINK "[]" R << std::endl;
	std::cout << PINK "Let's go!" R << std::endl << std::endl;

	try
	{
		make_arr(choose_type(), choose_index(0));
	}
	catch(const std::exception &e)
	{
		std::cout << PINK "Leaving already? Bye" R << std::endl;
		return (1);
	}
	
	return (0);
}

// Disables ctrl-C
void sigint_handler(int signal)
{
	(void)signal;
}

// Lets user select the data type to create an array from
int choose_type()
{
	std::cout << PINK "What type do you want to try?" << std::endl;
	std::string options[4] = {"char", "int", "double", "string"};

	while (true)
	{
		std::string buff = user_input(" TYPE: char | int | double | string");
			
		for (int i = 0; i < 4; i++)
			if (!options[i].compare(buff))
				return (i);

		std::cout << RED << "invalid selection, please try again" R << std::endl << std::endl;
	}

}

// Lets user choose an index - for size (0) or for access (1)
int	choose_index(int code)
{
	std::string prompt = "n index";
	if (!code)
	{
		std::cout << std::endl << PINK "How many indexes will your array contain? (Max 10)" << std::endl;
		prompt = " number of indexes";
	}
	
	while (true)
	{
		std::string buff = user_input(prompt);
		std::cout << std::endl;
		
		if (check_type(buff, INT) && (code || (!code && atoi(buff.c_str()) <= 10)))
			return (atoi(buff.c_str()));

		std::cout << RED << "invalid number, please try again" R << std::endl << std::endl;
	}
}

// Creates array + accesses user-chosen index
void make_arr(int type, int size)
{
	Array<std::string> str_arr(size);
	arr_input(str_arr, type);
	
	std::cout << std::endl << PINK "Great! Now let's select an index for you to print!" << std::endl;
	int index = choose_index(1);
	std::cout << GREY "Index " << index << ":" R << std::endl;

	try
	{
		if (type == CHAR)
		{
			Array<char>arr(size);
			for (int i = 0; i < size; i++)
				arr[i] = str_arr[i][0];
			std::cout << BLUE << arr[index] << R << std::endl;
		}
		else if (type == INT)
		{
			Array<int>arr(size);
			for (int i = 0; i < size; i++)
				arr[i] = atoi(str_arr[i].c_str());
			std::cout << BLUE << arr[index] << R << std::endl;
		}
		else if (type == DOUBLE)
		{
			Array<double>arr(size);
			for (int i = 0; i < size; i++)
				arr[i] = strtod(str_arr[i].c_str(), NULL);
			std::cout << BLUE << arr[index] << R << std::endl;
		}
		else if (type == STRING)
			std::cout << BLUE << str_arr[index] << R << std::endl;
	}
	catch (OutOfBoundsException &e)
	{
		std::cout << RED "Error: " << e.what() << R << std::endl;
	}
}

// Retrieves index content from user
void arr_input(Array<std::string> &arr, int type)
{
	int i = 0;

	while (i < arr.size())
	{
		try
		{
			std::string prompt = " value for index ";
			std::string new_element = user_input(prompt.append(1, i + '0'));
			if (check_type(new_element, type))
				arr[i++] = new_element;
			else
				std::cout << RED "Error: input doesn't comply with data type format. Please try again!" R << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << RED "Error: " << e.what() << R << std::endl;
			throw ;
		}
	}
}

// Checks if the user string matches the selected type format
int check_type(std::string str, int type)
{
	if (type == CHAR && str.size() == 1 && isprint(str[0]))
		return (true);
	if (type == STRING)
	{
		for (int i = 0; str[i]; i++)
			if (!isprint(str[i]))
				return (false);
		return (true);
	}

	int sign = 0;
	if (str[0] == '-' || str[0] == '+')
		sign++;

	size_t stop = str.find_first_not_of("0123456789", sign);
	if (type == DOUBLE && str[stop] == '.')
		if (str[stop +1] && str.find_first_not_of("0123456789", stop +1) == str.npos)
			stop = str.npos;
	
	if (stop == str.npos)
	{
		try
		{
			double res = strtod(str.c_str(), NULL);
			if (type == DOUBLE || (type == INT && res <= INT_MAX && res >= INT_MIN))
				return (true);
		}
		catch (std::exception &e)
		{}
	}
	
	return (false);
}

// Retrieves user input
std::string user_input(std::string type)
{
	std::cout << GREY "Please type a" << type << ":" << std::endl;
	std::cout << R " > ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (EofException());

	return (buff);
}
