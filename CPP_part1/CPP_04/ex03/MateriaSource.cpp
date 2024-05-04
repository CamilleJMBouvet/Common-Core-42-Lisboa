/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:09:16 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/03 14:43:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//----------------- Constructor/Destructor -----------------
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->stored[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.stored[i])
			this->stored[i] = src.stored[i]->clone();
		else
			this->stored[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->stored[i])
			delete this->stored[i];
}

//---------------- Copy assignement operator ---------------
MateriaSource	&MateriaSource::operator=(MateriaSource const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (src.stored[i])
				this->stored[i] = src.stored[i]->clone();
			else
				this->stored[i] = NULL;
		}
	}
	return (*this);
}

//-------------------- Action functions --------------------
void	MateriaSource::learnMateria(AMateria *src)
{
	if (!src)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->stored[i])
		{
			this->stored[i] = src->clone();
			delete src;
			return ;
		}
	}

	std::cout << RED "Error: too many Materias stored for learning" R << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while (i < 4)
	{
		if (this->stored[i] && !type.compare(this->stored[i]->getType()))
			break;
		i++;
	}
	if (i == 4)
	{
		std::cout << RED "Error: type of Materia not found" R << std::endl;
		return (NULL);
	}
	if (type[0] && (!type.compare("cure") || !type.compare("ice")))
	{
		AMateria *materia = this->stored[i];
		this->stored[i] = NULL;
		return (materia);
	}
	else
	{
		std::cout << RED "Error: Invalid type of Materia" R << std::endl;
		return (NULL);
	}
}
