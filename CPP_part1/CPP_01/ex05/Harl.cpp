/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:05:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/22 15:46:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstring>

# define WHITE		"\001\033[1;37m\002"
# define RED		"\001\033[0;31m\002"
# define R			"\001\033[1;00m\002"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::complain(std::string level)
{
	std::string	complaint[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
		if (!level.compare(complaint[i]))
			(this->*func[i])();
}

void	Harl::debug(void)
{
	std::cout << WHITE "[ DEBUG ]" << std::endl << RED \
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"\
	 R << std::endl;
}

void	Harl::info(void)
{
	std::cout << WHITE "[ INFO ]" << std::endl << RED \
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"\
	 R << std::endl;
}

void	Harl::warning(void)
{
	std::cout << WHITE "[ WARNING ]" << std::endl << RED \
	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."\
	 R << std::endl;
}

void	Harl::error(void)
{
	std::cout << WHITE "[ ERROR ]" << std::endl << RED \
	"This is unacceptable! I want to speak to the manager now."\
	 R << std::endl;
}
