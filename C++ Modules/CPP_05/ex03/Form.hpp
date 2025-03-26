/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:01:42 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/16 20:20:40 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

// -LIBRARIES-
# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"

// -MACROS-
# define GREY		"\001\033[1;37m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREEN		"\001\033[1;38;2;174;231;202m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -CLASS-
class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const &src);
		virtual ~Form();

		Form		&operator=(Form const &src);

		std::string	getName()const;
		int			getSignGrade()const;
		int			getExecGrade()const;
		bool		isSigned()const;

		void		beSigned(Bureaucrat &bur);
		bool		execute(Bureaucrat const &executor)const;

		class FormExceptions: public std::exception
		{};
		class GradeTooHighException: public Form::FormExceptions
		{
			public:
				virtual const char *what()const throw();
		};
		class GradeTooLowException: Form::FormExceptions
		{
			public:
				virtual const char *what()const throw();
		};
		class AlreadySignedException: public Form::FormExceptions
		{
			public:
				virtual const char *what()const throw();
		};

		class FormNotSignedException: public Form::FormExceptions
		{
			public:
				virtual const char *what()const throw();
		};
		class ExecutorTooLowException: public Form::FormExceptions
		{
			public:
				virtual const char *what()const throw();
		};

	protected:
		virtual void	executeAction()const;

	private:
		std::string const _name;
		int const _sign_grade;
		int const _exec_grade;
		bool _signed;

		Form();
};

std::ostream	&operator<<(std::ostream &o, Form const &instance);

#endif
