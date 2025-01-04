/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:56:17 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/04 14:28:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TO-DOS:
	- Last safety tests*/

// -LIBRARIES-
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <csignal>
#include <climits>

// -MACROS-
// Colours:
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"
// Codes:
# define SIGN		0
# define EXEC		1
// Intro strings:
# define SIGN_INTRO	"Now is the time to sign the forms!"
# define EXEC_INTRO	"Final job: execute the forms!"

// -FUNCTION DEFINITION-
void		sigint_handler(int signal);
std::string	user_string(std::string type);
int			int_input(std::string buff, int limit);
int			create_forms(Form **form_arr);
void		form_action(Bureaucrat boss, Form **form_arr, int indexes, int code);

// -FUNCTIONS-
int main()
{
	std::cout << PURPLE "---------------- COFFEE-MAKING ----------------" R << std::endl;
	std::signal(SIGINT, sigint_handler);

	Bureaucrat boss("Boss", 1);
	Form *form_arr[4] = {NULL, NULL, NULL, NULL};

	std::cout << GREY "Welcome, evaluator! Today, you're the " BLUE << boss << R << std::endl << std::endl;

	try
	{
		int indexes = create_forms(form_arr);
		if (!indexes)
		{
			std::cout << PINK "No form for today? Alright, bye!" R << std::endl;
			return (0);
		}

		std::cout << GREY "You have created " BLUE << indexes << GREY " form(s)." R << std::endl;
		form_action(boss, form_arr, indexes, SIGN);
		form_action(boss, form_arr, indexes, EXEC);

		std::cout << PURPLE "Thanks for your help! Bye now!" R << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << PURPLE "Leaving already? :'(" R << std::endl;
	}

	for (int i = 0; form_arr[i] && i < 3; i++)
		if (form_arr[i])
			delete form_arr[i];
}

// Disables ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Retrieves user input for string
std::string	user_string(std::string type)
{
	std::cout << GREY "Please choose a " << type << ":" << std::endl;
	std::cout << R " > ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (std::exception());

	return (buff);
}

// Checks if input number is valid and within range
int	int_input(std::string buff, int limit)
{
	if (buff.size() > 10 || buff.find_first_not_of("0123456789") != std::string::npos)
		return (-1);

	long nb = atol(buff.c_str());

	if (nb < 1 || nb > limit || nb > 3)
		return (-1);

	return (nb);
}

// Creates forms, add them to array, return number of forms created
int	create_forms(Form **form_arr)
{
	std::string buff;
	Intern intern;
	int index = 0;

	std::cout << PINK "Meet your corporate slave, " BLUE "Intern" \
	PINK ". He'll create all the forms for you. You can create up to 3 forms." << std::endl;
	std::cout << PINK "What do you want to do?" << std::endl;

	do
	{
		std::cout << std::endl << GREY "1 - Create a form | 0 - Be done" R << std::endl;
		std::cout << R " > ";

		getline(std::cin, buff);
		if (std::cin.eof())
			throw(std::exception());

		if (!buff.compare("1"))
			try
			{
				Form *newform = intern.makeForm(user_string("form"), user_string("target"));
				form_arr[index++] = newform;
			}
			catch (Intern::InvalidFormException &e)
			{
				std::cout << RED << "Exception caught: " << e.what() << R << std::endl;
			}

	} while (buff.compare("0") && index < 3);

	return (index);
}

// Lets user select a form, executes action specified by code
void	form_action(Bureaucrat boss, Form **form_arr, int indexes, int code)
{
	std::string buff;
	std::string	intro[2] = {SIGN_INTRO, EXEC_INTRO};

	std::cout << std::endl << PINK << intro[code];

	do
	{
		std::cout << std::endl << GREY "Pick a form: 1-" BLUE << indexes << GREY " | 0 - Be done" R << std::endl;
		std::cout << R " > ";
		getline(std::cin, buff);

		if (std::cin.eof())
			throw (std::exception());

		int nb = int_input(buff, indexes);
		if (nb != -1 && buff.compare("0"))
		{
			if (!code)
				boss.signForm(*form_arr[nb -1]);
			else
				boss.executeForm(*form_arr[nb -1]);
		}
	} while (buff.compare("0"));
}
