/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:27:56 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 22:39:50 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP

// -LIBRARIES-
#include <iostream>
#include "Bureaucrat.hpp"

// -MACROS-
# define GREY	"\001\033[1;37m\002"
# define BLUE	"\001\033[1;38;2;147;222;255m\002"
# define RED	"\001\033[1;31m\002"
# define R		"\001\033[1;00m\002"

class Bureaucrat;

// -CLASS-
class Form
{
	public:
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const &src);
		~Form();

		Form 		&operator=(Form const &src);

		std::string	getName()const;
		int			getSignGrade()const;
		int			getExecGrade()const;
		bool		isSigned()const;

		void		beSigned(Bureaucrat &bur);

		class FormExceptions: public std::exception
		{};
		class GradeTooHighException: public Form::FormExceptions
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public Form::FormExceptions
		{
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedException: public Form::FormExceptions
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const _name;
		int const _sign_grade;
		int const _exec_grade;
		bool _signed;

		Form();

};

std::ostream	&operator<<(std::ostream &o, const Form &instance);

#endif
