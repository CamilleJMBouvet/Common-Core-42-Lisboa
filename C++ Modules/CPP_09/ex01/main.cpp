/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:16:55 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/22 16:09:11 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include "RPN.hpp"

// -MACROS-
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define GREEN	"\001\033[1;38;2;174;231;202m\002"
#define GREY	"\001\033[1;37m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

//Main
int main(int ac, char **av)
{
	std::cout << PURPLE "---------------- RPN ----------------" R << std::endl;
	try
	{
		if (ac != 2)
			throw (std::runtime_error("Invalid number of arguments\nExpected: ./[programme] [input file]"));
		std::string expr = av[1];

		RPN rpn(expr);
		std::cout << GREY "-> " GREEN << rpn << R << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED "ERROR: " << e.what() << R << std::endl;
	}
}

//ENTRIES EXAMPLES:
 /* > "8 9 * 9 - 9 - 9 - 4 - 1 +" 			 	=> 42
	> "7 7 * 7 -"								=> 42
	> "1 2 * 2 / 2 * 2 4 - +"					=> 0
	> "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"	=> 42
	"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"	=> 15
 */