/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:59:35 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/15 15:25:53 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include <csignal>
#include <climits>
#include <iomanip>
#include <cmath>
#include "iter.hpp"

// -MACROS-
//-Data types-
#define	CHAR	0
#define INT		1
#define DOUBLE	2
#define STRING	3
//-Output colours-
#define GREY	"\001\033[1;37m\002"
#define PINK	"\001\033[1;38;5;225m\002"
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define BLUE	"\001\033[1;38;2;147;222;255m\002"
#define GREEN	"\001\033[1;38;2;174;231;202m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

// -CLASSES-
class EofException: public std::exception
{};

// -FUNCTION DEFINITION-
//-General-
void	sigint_handler(int signal);
int		choose_type();
//-Array-making-
void	char_arr();
void	int_arr();
void	double_arr();
void	string_arr();
//-Helper functions-
std::string	*make_arr(int type);
std::string	user_input(std::string type);
int			check_type(std::string str, int type);
//-Type-specific functions-
void	print_green(char &c);
void	print_case_invert(char &c);
void	print_pink(int &i);
void	print_mult_2(int &i);
void	print_purple(double &d);
void	print_div_2(double &d);
void	print_blue(std::string &str);
void	print_backwards(std::string &str);

// -FUNCTIONS-
int main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- ITER ----------------" R << std::endl;

	std::cout << GREY "Welcome! Today you'll be choosing a data type, creating an array, and choosing a function to apply." << std::endl;
	std::cout << "This will help show how the template function " PINK "iter()" GREY " works." << std::endl << std::endl;

	try
	{
		int choice = choose_type();
		if (choice == CHAR)
			char_arr();
		else if (choice == INT)
			int_arr();
		else if (choice == DOUBLE)
			double_arr();
		else if (choice == STRING)
			string_arr();
	}
	catch (EofException &e)
	{
		std::cout << PINK "Leaving already? Bye!" R << std::endl;
		return (1);
	}

	return (0);
}

// Disables ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Lets user select the data type to create an array from
int		choose_type()
{
	std::cout << PINK "What type do you want to try?" << std::endl;
	std::string buff;
	std::string options[4] = {"char", "int", "double", "string"};

	while (true)
	{
		std::cout << GREY "TYPE: char | int | double | string"  << std::endl;
		std::cout << R " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw(EofException());

		for (int i = 0; i < 4; i++)
			if (!options[i].compare(buff))
				return (i);

		std::cout << RED << "invalid selection, please try again" R << std::endl << std::endl;
	}
}

// Creates char array + makes user choose function to send to template
void	char_arr()
{
	std::string *arr = make_arr(CHAR);
	char c_arr[5];
	for (int i = 0; i < 5; i++)
		c_arr[i] = arr[i][0];
	delete[] arr;

	std::cout << std::endl << PINK "Please choose a function:" << std::endl;
	std::string buff;
	do
	{
		std::cout << PINK "Press 1 for " GREY "print_green()" PINK " | Press 2 for " GREY "print_case_invert()" << R << std::endl;
		std::cout << R << " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw (EofException());
		if (!buff.compare("1"))
			iter(c_arr, 5, print_green);
		else if (!buff.compare("2"))
			iter(c_arr, 5, print_case_invert);
	} while (!buff.compare("1") && !buff.compare("2"));
}

// Creates int array + makes user choose function to send to template
void	int_arr()
{
	std::string *arr = make_arr(INT);
	int i_arr[5];
	for (int i = 0; i < 5; i++)
		i_arr[i] = atoi(arr[i].c_str());
	delete[] arr;

	std::cout << std::endl << PINK "Please choose a function:" << std::endl;
	std::string buff;
	do
	{
		std::cout << PINK "Press 1 for " GREY "print_pink()" PINK " | Press 2 for " GREY "print_mult_2()" << R << std::endl;
		std::cout << R << " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw(EofException());
		if (!buff.compare("1"))
			iter(i_arr, 5, print_pink);
		else if (!buff.compare("2"))
			iter(i_arr, 5, print_mult_2);
	} while (!buff.compare("1") && !buff.compare("2"));
}

// Creates double array + makes user choose function to send to template
void	double_arr()
{
	std::string *arr = make_arr(DOUBLE);
	double d_arr[5];
	for (int i = 0; i < 5; i++)
		d_arr[i] = strtod(arr[i].c_str(), NULL);
	delete[] arr;

	std::cout << std::endl << PINK "Please choose a function:" << std::endl;
	std::string buff;
	do
	{
		std::cout << PINK "Press 1 for " GREY "print_purple()" PINK " | Press 2 for " GREY "print_div_2()" << R << std::endl;
		std::cout << R << " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw(EofException());
		if (!buff.compare("1"))
			iter(d_arr, 5, print_purple);
		else if (!buff.compare("2"))
			iter(d_arr, 5, print_div_2);
	} while (!buff.compare("1") && !buff.compare("2"));
}

// Creates string array + makes user choose function to send to template
void	string_arr()
{
	std::string *arr = make_arr(STRING);
	std::string s_arr[5];
	for (int i = 0; i < 5; i++)
		s_arr[i] = arr[i];
	delete[] arr;

	std::cout << std::endl << PINK "Please choose a function:" << std::endl;
	std::string buff;
	do
	{
		std::cout << PINK "Press 1 for " GREY "print_blue()" PINK " | Press 2 for " GREY "print_backwards()" << R << std::endl;
		std::cout << R << " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw(EofException());
		if (!buff.compare("1"))
			iter(s_arr, 5, print_blue);
		else if (!buff.compare("2"))
			iter(s_arr, 5, print_backwards);
	} while (!buff.compare("1") && !buff.compare("2"));
}

// Creates a 5 index array, retrieves its content from user, checks if format is correct for chosen type
std::string	*make_arr(int type)
{
	std::cout << std::endl << PINK "Let's create your array! It must contain 5 elements." << std::endl;
	std::string *arr = new std::string[5];
	std::string buff;
	int i = 0;

	while (i < 5)
	{
		try
		{
			std::string prompt = "value for index ";
			std::string new_element = user_input(prompt.append(1, i + '0'));
			if (check_type(new_element, type))
				arr[i++] = new_element;
			else
				std::cout << RED "Error: input doesn't comply with data type format. Please try again!" R << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			delete[] arr;
			throw ;
		}
	}
	return (arr);
}

// Checks if the user string matches the selected type format
int		check_type(std::string str, int type)
{
	if (type == CHAR && str.size() == 1 && isprint(str[0]))
		return (true);
	else if (type == STRING)
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
std::string	user_input(std::string type)
{
	std::cout << GREY "Please type a " << type << ":" << std::endl;
	std::cout << R " > ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (EofException());

	return (buff);
}

// Prints char in green
void	print_green(char &c)
{
	std::cout << GREEN << c << R << std::endl;
}

// Switches char's case + prints it
void	print_case_invert(char &c)
{
	if (islower(c))
		c = toupper(c);
	else if (isupper(c))
		c = tolower(c);

	std::cout << GREY << c << R << std::endl;
}

// Prints int in pink
void	print_pink(int &i)
{
	std::cout << PINK << i << R << std::endl;
}

// Multiplies int by 2 + prints it
void	print_mult_2(int &i)
{
	if ((i > INT_MAX / 2) || (i < INT_MIN / 2))
		std::cout << RED "int overflow!" R << std::endl;
	else
		std::cout << GREY << i * 2 << R << std::endl;
}

// Prints double in purple
void	print_purple(double &d)
{
	std::cout << PURPLE << d << R << std::endl;
}

// Divides double by 2 + prints it
void	print_div_2(double &d)
{
		std::cout << GREY << std::fixed << std::setprecision(3) << d / 2.0 << R << std::endl;
}

// Prints string in blue
void	print_blue(std::string &str)
{
	std::cout << BLUE << str << R << std::endl;
}

// Prints string backwards
void	print_backwards(std::string &str)
{
	for (int i = str.size(); i >= 0; i--)
		std::cout << GREY << str[i];
	std::cout << R << std::endl;
}

