/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:01:11 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/19 19:54:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

// -LIBRARIES-
# include <iostream>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

// -MACROS-
# define GREY		"\001\033[1;37m\002"
# define PHIL		"\001\033[0m\002\t\001\033[1m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREEN		"\001\033[1;38;2;174;231;202m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

# ifndef NULL
# define NULL		0
# endif

// -CLASS-
class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern	&operator=(Intern const &src);

		Form	*makeForm(std::string form, std::string const target);
		Form	*makePresForm(std::string &target);
		Form	*makeRobForm(std::string &target);
		Form	*makeShrubForm(std::string &target);

		class InvalidFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
