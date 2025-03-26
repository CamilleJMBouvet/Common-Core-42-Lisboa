/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:54:42 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 21:28:21 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <csignal>

// -MACROS-
//Colours
# define GREY	"\001\033[1;37m\002"
# define PINK	"\001\033[1;38;5;225m\002"
# define PURPLE	"\001\033[1;38;2;209;174;231m\002"
# define BLUE	"\001\033[1;38;2;147;222;255m\002"
# define R		"\001\033[1;00m\002"
//Choices
# define FORM_CHOICE	"| 1 - Presidential Pardon " \
	"| 2 - Robotomy Request | 3 - Shrubbery Creation | 0 - Go back"
# define ACTION_CHOICE	"TYPE: | 1 - sign | 2 - execute | 0 - Go back |"


// -FUNCTION DEFINITION-
void		sigint_handler(int signal);
std::string	user_string(std::string type);
void		choose_form(Bureaucrat &trainee, std::string target);
void		handle_form(Bureaucrat &trainee, AForm &form);
void		call_boss(AForm &form, int code);

// -FUNCTIONS-
int	main()
{
	std::cout << PURPLE "---------------- Form B28 ----------------" R << std::endl;
	std::signal(SIGINT, sigint_handler);

	try
	{
		Bureaucrat trainee("Trainee", 42);
		std::cout << std::endl << PINK "Welcome back, let's do some more administrative stuff with our new friend "\
		 << trainee << R << std::endl;

		std::string target = user_string("target");

		std::cout << std::endl << PINK "There's a bunch of forms to sign and execute. Let's go!" R << std::endl;
		choose_form(trainee, target);
	}
	catch (std::exception &e)
	{
		std::cout << PINK "Leaving already? :'(" R << std::endl;
		return (0);
	}
	std::cout << PINK "Thanks for your help! Bye now!" R << std::endl;
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
	std::cout << R "> ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (std::exception());

	if (buff.empty())
		buff = "Evaluation sheet";

	return (buff);
}

// Lets user select a form
void	choose_form(Bureaucrat &bur, std::string target)
{
	PresidentialPardonForm	pp_form(target);
	RobotomyRequestForm		rr_form(target);
	ShrubberyCreationForm	sc_form(target);

	void *form_arr[3] = {&pp_form, &rr_form, &sc_form};

	std::cout << std::endl << GREY "Choose a form: " FORM_CHOICE << std::endl;
	std::string buff;

	do
	{
		std::cout << R "> ";
		getline(std::cin, buff);
		if (std::cin.eof())
			throw(std::exception());

		if (!buff.compare("1") || !buff.compare("2") || !buff.compare("3"))
		{
			int index = atoi(buff.c_str()) -1;
			handle_form(bur, *static_cast<AForm*>(form_arr[index]));
			std::cout << std::endl << PINK "You're back to choosing a form!" << std::endl;
			std::cout << GREY FORM_CHOICE << std::endl;
		}
	} while (buff.compare("0"));
}

// Lets user select an action for the form
void	handle_form(Bureaucrat &bur, AForm &form)
{
	std::cout << std::endl << PINK "What do you want to do with " BLUE \
	<< form.getName() << PINK "?" R << std::endl;

	std::string buff;

	do
	{
		std::cout << GREY ACTION_CHOICE R << std::endl;
		std::cout << R "> ";
		getline(std::cin, buff);
		if (std::cin.eof())
			throw (std::exception());

		if (!buff.compare("1"))
		{
			if (!bur.signForm(form) && !form.isSigned())
				call_boss(form, 0);
		}
		else if (!buff.compare("2"))
		{
			if (!bur.executeForm(form) && form.isSigned())
				call_boss(form, 1);
			else if (!form.isSigned())
				continue;
			std::cout << PINK "Form executed!" R << std::endl;
			return ;
		}
	} while (buff.compare("0"));
}

// Use a Bureaucrat with max rank to sign/execute form
void	call_boss(AForm &form, int code)
{
	Bureaucrat boss("Boss", 1);
	std::cout << PINK "There's no time to upgrade the trainee, just call the " \
	BLUE << boss.getName() << R << std::endl;

	if (!code)
		boss.signForm(form);
	else
		boss.executeForm(form);
}
