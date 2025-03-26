/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:39:46 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 22:45:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

// -LIBRARIES-
# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"

// -MACROS-
# define GREY	"\001\033[1;37m\002"
# define BLUE	"\001\033[1;38;2;147;222;255m\002"
# define RED	"\001\033[1;31m\002"
# define R		"\001\033[1;00m\002"

// -CLASS-
class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm const &src);
		virtual	~AForm();

		AForm		&operator=(AForm const &src);

		std::string	getName()const;
		int			getSignGrade()const;
		int			getExecGrade()const;
		bool		isSigned()const;

		void		beSigned(Bureaucrat &bur);
		bool		execute(Bureaucrat const &executor)const;

		class AFormExceptions: public std::exception
		{};
		class GradeTooHighException: public AForm::AFormExceptions
		{
			public:
				virtual const char *what()const throw();
		};
		class GradeTooLowException: public AForm::AFormExceptions
		{
			public:
				virtual const char *what()const throw();
		};
		class AlreadySignedException: public AForm::AFormExceptions
		{
			public:
				virtual const char *what()const throw();
		};

		class FormNotSignedException: public AForm::AFormExceptions
		{
			public:
				virtual const char *what()const throw();
		};
		class ExecutorTooLowException: public AForm::AFormExceptions
		{
			public:
				virtual const char *what()const throw();
		};

	protected:
		virtual void	executeAction()const = 0;

	private:
		std::string const _name;
		int const _sign_grade;
		int const _exec_grade;
		bool _signed;

		AForm();
};

std::ostream	&operator<<(std::ostream &o, const AForm &instance);

#endif
