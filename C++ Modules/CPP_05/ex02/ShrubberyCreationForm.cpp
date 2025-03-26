/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:54:25 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/11 22:33:54 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//----------------- Constructor/Destructor -----------------
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm(src), _target(src.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

//---------------- Copy assignement operator ---------------
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

//--------------- Private attribute accessors --------------
std::string	ShrubberyCreationForm::getTarget()const
{
	return (this->_target);
}

//-------------------- Action functions --------------------
void	ShrubberyCreationForm::executeAction()const
{
	try
	{
		std::string path = std::getenv("PWD");
		if (path.empty())
			throw (std::exception());

		path += "/" + this->_target + "_shrubbery";
		std::ofstream outfile(path.c_str());
		if (!outfile)
			throw (std::exception());
		outfile << TREE << std::endl << TREE << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception caught: Runtime error" R << std::endl << std::endl;
	}
}
