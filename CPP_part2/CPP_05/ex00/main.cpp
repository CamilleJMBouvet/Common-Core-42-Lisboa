/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/12/07 18:13:07 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "Bureaucrat.hpp"
#include <csignal>
#include <cstdlib>

// -MACROS-
// Colours
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"
// Int caps
# define MIN_CAP	"-2147483650"
# define MAX_CAP	"2147483650"

// -FUNCTIONS DEFINITION-
void			sigint_handler(int signal);
std::string		user_string(std::string type);
int				user_nb(std::string type);
std::string		buff_check(std::string buff);
void			regrade_bureaucrat(Bureaucrat &bur);
int				handle_exceptions(long grade);

// - FUNCTIONS-
int	main()
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- Bureaucrat ----------------" R << std::endl;
	std::cout << std::endl << PINK \
	"Welcome to Loja do Cidadao! It's time to create a Bureaucrat." << std::endl;

	try
	{
		Bureaucrat	bur(user_string("Bureaucrat name"), user_nb("Bureaucrat grade"));
		std::cout << bur << std::endl;

		std::cout << std::endl << PINK "Now let's create a clone of " PINK \
		<< bur.getName() << std::endl;
		Bureaucrat bur_clone(bur);
		std::cout << GREY "Clone " << bur_clone << std::endl;

		regrade_bureaucrat(bur);

		std::cout << std::endl << PINK "Now let's compare the grades of " BLUE << bur.getName() \
		<< PINK " and their clone: " << std::endl;
		std::cout << bur << std::endl;
		std::cout << GREY "Clone " << bur_clone << std::endl;

		std::cout << std::endl << PINK "Let's equalise them and assign " BLUE << bur.getName() \
		<< PINK "'s grade to their clone: " << std::endl;
		bur_clone = bur;
		std::cout << bur << std::endl;
		std::cout << GREY "Clone " << bur_clone << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << std::endl << PINK "You're leaving already? Bye :(" R << std::endl;
		return (0);
	}

	std::cout << std::endl << PINK \
	"Yayyy. How fun was that. Bureaucracy is a sacred art. Bye now" R << std::endl;
}

// Disables ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Retrieves user input for string
std::string	user_string(std::string type)
{
	std::cout << GREY "Please choose a " << type << ":" <<std::endl;
	std::cout << R "> ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (std::exception());

	if (buff.empty())
		buff = "Anonymous bureaucrat";

	return (buff);
}

// Retrieves user input for int + handles exceptions
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
			throw (std::exception());

		buff = buff_check(buff);
		grade = std::atol(buff.c_str());
		if (!buff.empty() && !handle_exceptions(grade))
			break ;
		std::cout << RED "Incorrect grade - Please try again!" R << std::endl;
		grade = 0;
	} while (!grade);

	return (grade);
}

// Ensures user input is of correct format + prevents long int overflow
std::string	buff_check(std::string buff)
{
	if (buff.empty())
		return ("");
	std::string newbuff = buff;
	if (buff[0] == '-' && buff.length() > 1)
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

// Loops allowing user to increment/decrement Bureaucrat's grade
void	regrade_bureaucrat(Bureaucrat &bur)
{
	std::cout << std::endl << PINK "You get to edit the grade of the original " BLUE \
	<< bur.getName() << PINK " !" << std::endl;
	std::cout << GREY "TYPE: + | - | done " << std::endl;
	std::string buff;

	do
	{
		std::cout << R "> ";
		getline(std::cin, buff);

		if (!buff.compare("-") && !handle_exceptions(bur.getGrade() +1))
			bur.decrement();
		if (!buff.compare("+") && !handle_exceptions(bur.getGrade() -1))
			bur.increment();
		if (std::cin.eof())
			throw (std::exception());
		std::cout << bur << std::endl;
	} while (buff.compare("done"));
}

// Handles exceptions for Bureaucrat grade cap
int	handle_exceptions(long grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		return (0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED "Exception caught: " << e.what() << R << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED "Exception caught: " << e.what() << R << std::endl;
	}
	return (1);
}


