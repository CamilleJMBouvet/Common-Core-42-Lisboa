/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:41 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/01 18:17:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// -LIBRARIES-
#include <iostream>

// -MACROS-
# define PINK		"\001\033[1;38;5;225m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define GREY		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"


class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat		&operator=(Bureaucrat const &src);

		std::string	getName(void)const;
		int			getGrade(void)const;

		void		increment(void);
		void		decrement(void);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		int	_grade;

		Bureaucrat();
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &instance);

#endif
