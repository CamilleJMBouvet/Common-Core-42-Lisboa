/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:15 by cbouvet           #+#    #+#             */
/*   Updated: 2025/01/22 11:16:46 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include <csignal>
#include <cmath>
#include "Serializer.hpp"

// -MACROS-
#define GREY	"\001\033[1;37m\002"
#define PINK	"\001\033[1;38;5;225m\002"
#define PURPLE	"\001\033[1;38;2;209;174;231m\002"
#define BLUE	"\001\033[1;38;2;147;222;255m\002"
#define RED		"\001\033[1;31m\002"
#define R		"\001\033[1;00m\002"

// -FUNCTION DEFINITION-
void		sigint_handler(int signal);
int			init_data_struct(Data &user_song);
void		set_default(Data &user_song);
std::string	user_string(std::string type);
int			int_input(std::string buff, int limit);

// -FUNCTIONS-
int	main(void)
{
	std::signal(SIGINT, sigint_handler);
	std::cout << PURPLE "---------------- SERIALIZER ----------------" R << std::endl;

	std::cout << PINK "What is Serialization?" R << std::endl;
	std::cout << "Serialization is the process of converting an object into a format that can later be reconstructed." \
	<< std::endl << "It allows to preserve the object's state, so that it can be restored without loss" \
	<< std::endl << std::endl;

	std::cout << PINK "Let's test this!" R << std::endl;
	std::cout << "We will register information about a song in a data struct \"Data\", that we can then serialize and deserialize" \
	<< std::endl << std::endl;

	Data user_song;
	if (!init_data_struct(user_song))
		return (1);

	std::cout << std::endl << PINK "Here's your entry: " R << std::endl;
	std::cout << user_song << std::endl;

	std::cout << PINK "Now let's serialize your data entry into an unsigned int pointer type: " R << std::endl;
	uintptr_t raw = Serializer::serialize(&user_song);
	std::cout << BLUE "• uintptr_t: " R << raw << std::endl << std::endl;

	std::cout << PINK "Last step: we'll reconstruct your entry into a new variable of type \"Data *\": " R << std::endl;
	Data *reconstruct_song = Serializer::deserialize(raw);
	std::cout << *reconstruct_song << std::endl;

	return (0);
}

// Disables CTRL-C
void	sigint_handler(int signal)
{
	(void)signal;
}

// Initializes Data data_struct with user input or default data
int	init_data_struct(Data &user_song)
{
	try
	{
		user_song.title = user_string("a song title");
		user_song.artist = user_string("its artist");
		user_song.album = user_string("its album");
		do
			user_song.year = int_input(user_string("its release year"), 2025);
		while (user_song.year < 0);
	}
	catch(std::exception &e)
	{
		return (0);
	}
	set_default(user_song);

	return (1);
}

// If all data entries were left blank, fills up with default info
void	set_default(Data &user_song)
{
	if (!user_song.title.compare("UNKNOWN") && !user_song.artist.compare("UNKNOWN") && \
	!user_song.album.compare("UNKNOWN") && !user_song.year)
	{
		user_song.title = "Never Gonna Give You Up";
		user_song.artist = "Rick Astley";
		user_song.album = "Whenever You Need Somebody";
		user_song.year = 1987;
	}
}

// Receives string from user & attributes default value if blank
std::string	user_string(std::string type)
{
	std::cout << GREY "Please enter " << type << ":" << std::endl;
	std::cout << R "> ";

	std::string buff;
	getline(std::cin, buff);
	if (std::cin.eof())
		throw (std::exception());

	if (!buff[0])
		return ("UNKNOWN");

	return (buff);
}

// Converts string into int, checks if obeys rules for year entry
int	int_input(std::string buff, int limit)
{
	std::string errmsg;
	long nb = atol(buff.c_str());

	if (buff.empty() || !buff.compare("UNKNOWN"))
		return (0);

	if (buff.size() > 10 || buff.find_first_not_of("0123456789") != buff.npos)
		errmsg = "invalid year";
	if (buff[0] == '-' && buff.substr(1).find_first_not_of("0123456789") == std::string::npos)
		errmsg = "year must be Anno Domini";
	if (nb > limit)
		errmsg = "future releases are not accepted";

	if (!errmsg.empty())
	{
		std::cerr << RED "Error: " << errmsg << R << std::endl;
		std::cerr << "(Why? Because I said so. My programme, my rules)" << std::endl << std::endl;
		return (-1);
	}

	return (nb);
}

// Overloads output for data struct Data
std::ostream	&operator<<(std::ostream &o, Data const &data_struct)
{
	o << BLUE "• Title: " R << data_struct.title << std::endl;
	o << BLUE "• Artist: " R << data_struct.artist << std::endl;
	o << BLUE "• Album: " R << data_struct.album << std::endl;
	o << BLUE "• Year: " R << data_struct.year << std::endl;
	return (o);
}
