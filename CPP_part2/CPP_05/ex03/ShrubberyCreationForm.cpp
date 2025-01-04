/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:02:23 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/18 17:56:00 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//----------------- Constructor/Destructor -----------------
ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): Form(src), _target(src.getTarget())
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
		std::cout << RED << "Exception caught: Runtime error" R << std::endl;
	}
}
