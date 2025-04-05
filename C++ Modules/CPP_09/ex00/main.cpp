/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:24:19 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/22 15:54:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

// -MACROS-
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

// -FUNCTION DEFINITION-
void	file_opener(std::fstream &file, std::string filename, std::ios_base::openmode mode);

// -FUNCTIONS-
// Main
int main(int ac, char **av)
{
	std::cout << PURPLE "---------------- btc ----------------" R << std::endl;
	try
	{
		if (ac != 2)
			throw (std::runtime_error("Invalid number of arguments\nExpected: ./[programme] [input file]"));

		std::fstream infile;
		std::fstream csvfile;
		file_opener(infile, av[1], std::ios::in);
		file_opener(csvfile, "data.csv", std::ios::in);

		BitcoinExchange btc(csvfile);

		std::string buff;
		getline(infile, buff);
		while (getline(infile, buff))
			btc.printRes(buff);
	}
	catch (std::exception &e)
	{
		std::cout << RED "ERROR: " << e.what() << R << std::endl;
	}
}

// Opens files and checks for potential failures
void	file_opener(std::fstream &file, std::string filename, std::ios_base::openmode mode)
{
	file.open(filename.c_str(), mode);
	
	if (!file.is_open())
		throw (std::ios_base::failure("Could not open file"));
	if (file.fail() || file.bad())
		throw (std::runtime_error("Failed to read from file"));
}

// INPUT.TXT example for you dear evaluator
/* date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
2025-02-23 | 2
2012-02-29 | 6j
1996-02-23 | 29 */
