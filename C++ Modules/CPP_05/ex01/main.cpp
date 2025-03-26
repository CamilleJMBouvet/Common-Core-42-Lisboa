/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:27:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 21:37:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <csignal>
#include <cstdlib>
#include <climits>
#include <cstddef>

// -MACROS-
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"
// Int caps
# define MIN_CAP	"-2147483650"
# define MAX_CAP	"2147483650"

// -FUNCTIONS DEFINITIONS-
void		sigint_handler(int signal);
Form		*create_form();
std::string	user_string(std::string type);
int			user_nb(std::string type);
std::string	buff_check(std::string buff);
void		choose_form(Bureaucrat &trainee, Form &form_user);
void		sign_form(Bureaucrat &trainee, Form &form);
void		upgrade_trainee(Bureaucrat &trainee);

// -FUNCTIONS-
int	main()
{
	std::cout << PURPLE "---------------- Maggots ----------------" R << std::endl;
	std::signal(SIGINT, sigint_handler);
	Form *form_user = NULL;

	try
	{
		std::cout << std::endl << PINK "In order to play, you'll have to create a " \
		BLUE "Form" PINK "." R << std::endl;
		form_user = create_form();
		if (!form_user)
			return (1);

		Bureaucrat	trainee("Trainee", 42);
		std::cout << std::endl << PINK "Meet " BLUE << trainee.getName() << PINK ", the newest Bureaucrat:" << std::endl;
		std::cout << trainee << std::endl;

		std::cout << PINK "You'll be helping them sign a bunch of forms today. Ready?" R << std::endl;
		choose_form(trainee, *form_user);

		std::cout << PINK "All forms are signed, great job! Bye now!" R << std::endl;
	}
	catch (std::exception &e)
	{
		if (form_user)
			delete form_user;
		std::cout << std::endl << PINK "You're leaving already? Bye :(" R << std::endl;
	}
}

// Disables ctrl-C
void		sigint_handler(int signal)
{
	(void)signal;
}

// Deals with form creation
Form	*create_form()
{
	while (1)
	{
		try
		{
			Form *form_user = new Form(user_string("form name"), user_nb("signing grade"), user_nb("execution grade"));
			std::cout << *form_user << std::endl;
			return (form_user);
		}
		catch (Form::FormExceptions &e)
		{
			std::cout << RED "Exception caught: " << e.what() << R << std::endl;
		}
	}
	return (NULL);
}
// Retrieves user input for string
std::string user_string(std::string type)
{
	std::cout << GREY "Please choose a " << type << ":" << std::endl;
	std::cout << R "> ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw(std::exception());

	if (buff.empty())
		buff = "Blank paper";

	return (buff);
}

// Retrieves user input for int
int	user_nb(std::string type)
{
	std::cout << GREY "Please choose a " << type << ":" << std::endl;
	long grade = 0;
	std::string buff;

	do
	{
		std::cout << R "> ";
		getline(std::cin, buff);
		if (std::cin.eof())
			throw(std::exception());

		buff = buff_check(buff);
		grade = std::atol(buff.c_str());
		if (!buff.empty() && grade <= INT_MAX && grade >= INT_MIN)
			break ;
		std::cout << RED "Incorrect grade - Please try again!" R << std::endl;
		grade = 0;
	} while (!grade);

	return (grade);
}

// Checks if user int is valid (no overflow, digits only)
std::string	buff_check(std::string buff)
{
	std::string newbuff = buff;

	if (buff.empty())
		return ("");
	if (buff[0] == '-')
		newbuff = &buff[1];
	if (newbuff.size() > 10)
		newbuff = &buff[1];
	if (newbuff.find_first_not_of("0123456789") != newbuff.npos)
		return ("");
	if (newbuff.size() > 10)
	{
		if (buff[0] == '-')
			return (MIN_CAP);
		return (MAX_CAP);
	}
	return (buff);
}

// Prompts user for action until all forms are signed
void	choose_form(Bureaucrat &trainee, Form &form_user)
{
	Form		form_presence("Presence sheet", 100, 50);
	Form		form_fund("Huge funds transfer", 2, 2);

	Form form_arr[3] = {form_presence, form_fund, form_user};

	while (!form_presence.isSigned() || !form_fund.isSigned() || !form_user.isSigned())
	{
		std::cout << std::endl << GREY "TYPE: | 1 | 2 | 3 |" << std::endl;
		std::cout << R "> ";

		std::string buff;
		getline(std::cin, buff);
		if (std::cin.eof())
			throw(std::exception());

		if (!buff.compare("1") || !buff.compare("2") || !buff.compare("3"))
		{
			int index = atoi(buff.c_str()) -1;
			sign_form(trainee, form_arr[index]);
		}
	}
}

// Signs form if possible - if not, shows message + suggests workarounds
void	sign_form(Bureaucrat &trainee, Form &form)
{
	std::cout << std::endl << form << R << std::endl ;
	Bureaucrat 	boss("Big Boss", 1);

	trainee.signForm(form);

	if (!form.isSigned() && trainee.getGrade() > form.getSignGrade())
	{
		std::cout << PINK "How do you want to solve that?" << std::endl \
		<< GREY "1 - Upgrade Trainee | 2 - Call the boss | 0 - Go back" << std::endl;
		std::string buff;

		do
		{
			std::cout << R "> ";
			getline(std::cin, buff);
			if (std::cin.eof())
				throw(std::exception());
		} while (buff.compare("1") && buff.compare("2") && buff.compare("0"));

		if (!buff.compare("1"))
		{
			upgrade_trainee(trainee);
			sign_form(trainee, form);
		}
		if (!buff.compare("2"))
		{
			std::cout << boss << std::endl;
			boss.signForm(form);
		}
	}
}

// Loop allowing user to increment trainee's grade
void		upgrade_trainee(Bureaucrat &trainee)
{
	std::string	buff;
	std::cout << GREY "TYPE: | + - Upgrade | 0 - Go back |" << std::endl;
	do
	{
		std::cout << R "> ";
		getline(std::cin, buff);
		if (std::cin.eof())
			throw(std::exception());

		if (!buff.compare("+"))
		{
			try
			{
				trainee.increment();
			}
			catch (Bureaucrat::GradeTooHighException &e)
			{
				std::cout << RED "Exception caught: " << e.what() << R << std::endl;
				return ;
			}
		}
		std::cout << trainee << std::endl;
	} while (buff.compare("0"));
}
