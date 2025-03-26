/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:38 by cbouvet           #+#    #+#             */
/*   Updated: 2024/12/07 15:16:52 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//----------------- Constructor/Destructor -----------------
Intern::Intern()
{}

Intern::Intern(Intern const &src)
{
	(void)src;
}

Intern::~Intern()
{}

//---------------- Copy assignement operator ---------------
Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return(*this);
}

//-------------------- Action functions --------------------
Form	*Intern::makeForm(std::string form, std::string target)
{
	int index = 0;
	Form *newform = NULL;

	std::string form_names[3] = {"presidential", "robotomy", "shrubbery"};
	Form *(Intern::*form_arr[3])(std::string &target) = {
		&Intern::makePresForm,
		&Intern::makeRobForm,
		&Intern::makeShrubForm };


	for (size_t i = 0; i < form.size(); i++)
		form[i] = tolower(form[i]);

	while (index < 3 && form.find(form_names[index]) == std::string::npos)
		index++;

	switch (index)
	{
		case 3:
			throw (Intern::InvalidFormException());
		default:
			newform = (this->*form_arr[index])(target);
			std::cout << BLUE "Intern" GREY " creates " BLUE << newform->getName() << R << std::endl;
	}
	return (newform);
}

Form	*Intern::makePresForm(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form		*Intern::makeRobForm(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeShrubForm(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

//----------------- Nested class functions -----------------
const char	*Intern::InvalidFormException::what() const throw()
{
	return ("Form name not recognised");
}
