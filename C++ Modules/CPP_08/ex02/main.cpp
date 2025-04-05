/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:28:05 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/22 15:44:53 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <vector>
#include <csignal>
#include <iostream>
#include "MutantStack.hpp"

// -MACROS-
#define GREY		"\001\033[1;37m\002"
#define PINK		"\001\033[1;38;5;225m\002"
#define PURPLE		"\001\033[1;38;2;209;174;231m\002"
#define BLUE		"\001\033[1;38;2;147;222;255m\002"
#define RED		"\001\033[1;31m\002"
#define R			"\001\033[1;00m\002"

// -ENUM-
enum cont_type
{
	QUEUE,
	VECTOR,
	LIST,
	DEQUE,
	MULTIMAP,
	MULTISET,
	DEFAULT
};

// -CLASSES-
class EofException: public std::exception {};
class EmptyException: public std::exception {};

// -TEMPLATES-

// Prints comparatively (if available) the contents of MutantStack + the container chosen:
// for undefined type "Container":
template <typename Container>
void	print_contents(MutantStack<std::string> &user_mutant, Container &cont, cont_type type)
{
	std::string cont_str[6] = {"", "VECTOR", "LIST", "DEQUE", "MULTIMAP", "MULTISET"};
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();
	typename Container::iterator it_cont = cont.begin();

	std::cout <<std::endl << GREY "MUTANTSTACK	" << cont_str[type] << std::endl;
	std::cout << "size - " BLUE << user_mutant.size() << GREY "	size - " BLUE << cont.size() << R << std::endl;

	while (it_mutant != user_mutant.end() && it_cont != cont.end())
		std::cout << BLUE << *it_mutant++ << "		" << *it_cont++ << R << std::endl;
}
// for multimap:
template<>
void	print_contents(MutantStack<std::string> &user_mutant, std::multimap<int, std::string> &cont, cont_type type)
{
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();
	typename std::map<int, std::string>::iterator it_cont = cont.begin();

	std::cout << std::endl << GREY "MUTANTSTACK	MULTIMAP" << std::endl;
	std::cout << "size - " BLUE << user_mutant.size() << GREY "	" BLUE << cont.size() << R << std::endl;

	for (; it_mutant != user_mutant.end(); it_mutant++, it_cont++)
		std::cout << BLUE << *it_mutant << "		" << it_cont->second << R << std::endl;
}
// for queue:
template <>
void	print_contents(MutantStack<std::string> &user_mutant, std::queue<std::string> &cont, cont_type type)
{
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();

	std::cout << std::endl << GREY "MUTANTSTACK	QUEUE" << std::endl;
	std::cout << "size - " BLUE << user_mutant.size() << "	size - " << cont.size() << R << std::endl;

	while (it_mutant != user_mutant.end() && !cont.empty())
	{
		std::cout << BLUE << *it_mutant++ << "		" << cont.front() << R << std::endl;
		cont.pop();
	}
}
// without comparison:
template<>
void	print_contents(MutantStack<std::string> &user_mutant, MutantStack<std::string> &cont, cont_type type)
{
	if (user_mutant.empty())
		throw (EmptyException());

	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();

	std::cout << std::endl << GREY "MUTANTSTACK" << std::endl;
	std::cout << "size - " BLUE << user_mutant.size() << R << std::endl;

	for (; it_mutant != user_mutant.end(); it_mutant++)
		std::cout << BLUE << *it_mutant << R << std::endl;
}

// Creates chosen container based on elements found in MutantStack
// with undefined type "Container":
template <typename Container>
void process_container(MutantStack<std::string> &user_mutant, Container &cont, cont_type type)
{
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();

	for (; it_mutant != user_mutant.end(); it_mutant++)
			cont.push_back(*it_mutant);

	print_contents<Container>(user_mutant, cont, type);
}
// with multimap:
template<>
void process_container(MutantStack<std::string> &user_mutant, std::multimap<int, std::string> &cont, cont_type type)
{
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();

	for (int i = 0; it_mutant != user_mutant.end() && i < user_mutant.size(); it_mutant++, i++)
		cont.insert(std::make_pair(i, *it_mutant));

	print_contents(user_mutant, cont, type);
}
// with multiset:
template<>
void process_container(MutantStack<std::string> &user_mutant, std::multiset<std::string> &cont, cont_type type)
{
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();

	for (; it_mutant != user_mutant.end(); it_mutant++)
			cont.insert(*it_mutant);

	print_contents(user_mutant, cont, type);
}
// with queue:
template<>
void process_container(MutantStack<std::string> &user_mutant, std::queue<std::string> &cont, cont_type type)
{
	MutantStack<std::string>::iterator it_mutant = user_mutant.begin();

	for (; it_mutant != user_mutant.end(); it_mutant++)
			cont.push(*it_mutant);

	print_contents(user_mutant, cont, type);
}

// -FUNCTION DEFINITION-
void	sigint_handler(int signal);
void	subject_test_list();
void	subject_test();
MutantStack<std::string>	create_mutant();
cont_type	choose_type();
void	make_container(MutantStack<std::string> &user_mutant, cont_type type);
std::string	user_input(std::string type);

// -FUNCTIONS-
int main()
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- MutantStack ----------------" R << std::endl;

	std::cout << GREY "Now for the last part, we've implemented" BLUE " iterators " GREY \
	" for the " BLUE "std::stack " GREY "container type." << std::endl;
	std::cout << PINK "Let's go!" R << std::endl << std::endl;

	subject_test();
	subject_test_list();

	try
	{
		MutantStack<std::string> user_mutant = create_mutant();
		print_contents(user_mutant, user_mutant, DEFAULT);
		make_container(user_mutant, choose_type());
	}
	catch (EofException &e)
	{
		std::cout << PINK "Leaving already? Bye" R << std::endl;
	}
	catch (EmptyException &e)
	{
		std::cout << std::endl << BLUE "Your stack is empty! There's nothing left to do but say goodbye!" R << std::endl;
	}
}

// Disables ctrl-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Runs code provided in the subject
void	subject_test()
{
	std::cout << PINK "First, let's check out the example taken from the subject." << std::endl;
	std::cout << PINK "We'll start with a " BLUE "std::stack" PINK ":" R << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

// Runs subject code with list for comparison purposes
void	subject_test_list()
{
	std::cout <<std::endl << PINK "Next, let's compare with what the same code adapted to a " BLUE \
	"std::list" PINK ". They should display the same results:" R << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;

	mstack.pop_back();
	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

// Gets user to create a MutantStack container - giving options to add or remove elements
MutantStack<std::string> create_mutant()
{
	std::cout << std::endl << PINK "Now, you get to fill up a stack of type std::string" R << std::endl;

	MutantStack<std::string> user_mutant;
	std::string options[] = {"push | pop | done"};
	std::string buff;

	do
	{
		buff = user_input("n option: push | pop | done");

		if (!buff.compare ("push"))
			user_mutant.push(user_input(" value to push"));
		else if (!buff.compare("pop"))
		{
			if (user_mutant.empty())
				std::cout << RED "Error: Container is empty!" R << std::endl;
			else
				user_mutant.pop();
		}
		else if (buff.compare("done"))
			std::cout << RED "ERROR: Incorrect input! Please try again." R << std::endl;
	} while (buff.compare("done"));

	return (user_mutant);
}

// Lets user choose a type of container to create
cont_type		choose_type()
{
	std::cout << std::endl << PINK "Which container do you want to work with?" R << std::endl;
	std::string options[6] = {"queue", "vector", "list", "deque", "multimap", "multiset"};

	do
	{
		std::string buff = user_input(" TYPE: queue | vector | list | deque | multimap | multiset");
		for (int i = 0; i < 6; i++)
			if (!buff.compare(options[i]))
				return (static_cast<cont_type>(i));

		std::cout << RED "ERROR: Invalid selection, please try again" R << std::endl;
	} while (true);
}

// Creates the chosen container + sends it to template function to get populated
void	make_container(MutantStack<std::string> &user_mutant, cont_type type)
{
	if (type == QUEUE)
	{
		std::queue<std::string> q;
		process_container(user_mutant, q, type);
	}
	else if (type == VECTOR)
	{
		std::vector<std::string> v;
		process_container(user_mutant, v, type);
	}
	else if (type == LIST)
	{
		std::list<std::string> l;
		process_container(user_mutant, l, type);
	}
	else if (type == DEQUE)
	{
		std::deque<std::string> d;
		process_container(user_mutant, d, type);
	}
	else if (type == MULTIMAP)
	{
		std::multimap<int, std::string> m;
		process_container(user_mutant, m, type);
	}
	else if (type == MULTISET)
	{
		std::multiset<std::string> s;
		process_container(user_mutant, s, type);
	}
}

// Retrieves string input from user
std::string user_input(std::string type)
{
	std::cout << GREY "Please type a" << type << ":" << std::endl;
	std::cout << R " > ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (EofException());

	return (buff);
}
