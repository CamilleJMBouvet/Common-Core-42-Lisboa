/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:54 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/15 15:09:08 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// -MACROS-
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define WHITE		"\001\033[1;37m\002"
# define R			"\001\033[1;00m\002"

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";

	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << WHITE << &brain << std::endl;
	std::cout << PINK << stringPTR << std::endl;
	std::cout << BLUE << &stringREF << std::endl;

	std::cout << WHITE << brain << std::endl;
	std::cout << PINK << *stringPTR << std::endl;
	std::cout << BLUE << stringREF << R << std::endl;
}
