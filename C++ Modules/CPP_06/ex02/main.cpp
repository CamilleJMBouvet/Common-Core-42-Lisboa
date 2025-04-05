/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:23:40 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/08 19:01:32 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// -MACROS-
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -FUNCTION DEFINITION-
Base 	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
bool	try_cast(Base &p, char subtype);

// -FUNCTIONS-
int main (void)
{
	std::cout << PURPLE "---------------- REAL TYPE ----------------" R << std::endl;
	std::cout << "We'll create a random subtype of Base." << std::endl;
	std::cout << "Then, we'll use dynamic_cast to check which subtype we created." << std::endl;
	std::cout << "In addition, we'll display the address: if the address exists and shows, then the subtype shown is correct!"\
	<< std::endl << std::endl;


	Base *test = generate();
	identify(test);

	std::cout << std::endl;

	if (test)
	{
		Base &test1 = *test;
		identify(test1);
	}
	else
		std::cerr << RED << "Error: variable points to NULL" << R << std::endl;
	
	delete test;
}

//Randomly instantiates A, B or C | returns it as a Base pter
Base	*generate(void)
{
	Base *test = NULL;

	srand(std::time(0));
	int subclass = rand() % 3;

	if (!subclass)
		test = new A;
	else if (subclass == 1)
		test = new B;
	else
		test = new C;

	std::cout << PINK "> The instantiation generated is of type: " GREY \
	<< static_cast<char>(subclass+65) << R << std::endl << std::endl ;

	return (test);
}

//Prints actual type of object pointed by p
void	identify(Base *p)
{
	std::cout << BLUE "CAST BY POINTER:" R << std::endl;

	if (!p)
	{
		std::cerr << RED << "Error: variable points to NULL" R << std::endl;
		return ;
	}

	std::cout << PINK << "• Class is of type: " R;
	if (dynamic_cast<A *>(p))
		std::cout << GREY << "A" << std::endl << PINK "• See pointer: " GREY << dynamic_cast<A *>(p) << R << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << GREY << "B" << std::endl << PINK "• See pointer: " GREY  << dynamic_cast<B *>(p) << R << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << GREY << "C" << std::endl << PINK "• See pointer: " GREY << dynamic_cast<C *>(p) << R << std::endl;
	else
		std::cerr << std::endl << RED << "Error detected: no subtype found" R << std::endl;
}

//Prints actual type of object pointed by p
void	identify(Base &p)
{
	std::cout << BLUE "CAST BY REFERENCE:" R << std::endl;
	std::cout << PINK << "• Class is of type: " R;

	if (try_cast(p, 'A'))
		return ;
	if (try_cast(p, 'B'))
		return ;
	if (try_cast(p, 'C'))
		return ;

	std::cerr << std::endl << RED << "Error detected: no subtype found" R << std::endl;
}

// Helper function - tries to cast to each subtype, returns an exception if fails
bool	try_cast(Base &p, char subtype)
{
	try
	{
		if (subtype == 'A')
		{
			(void)dynamic_cast<A &>(p);
			std::cout << GREY "A" << std::endl << PINK "• See reference: " GREY << dynamic_cast<A &>(p) << R << std::endl;
		}
		if (subtype == 'B')
		{
			(void)dynamic_cast<B &>(p);
			std::cout << GREY "B" << std::endl << PINK "• See reference: " GREY << dynamic_cast<B &>(p) << R << std::endl;
		}
		if (subtype == 'C')
		{
			(void)dynamic_cast<C &>(p);
			std::cout << GREY "C" << std::endl << PINK "• See reference: " GREY << dynamic_cast<C &>(p) << R << std::endl;
		}
		return (true);
	}
	catch (std::exception &e)
	{
		return (false);
	}
}
