/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:24:10 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/08 15:56:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

// -LIBRARIES-
# include <iostream>
# include <sstream>
# include <fstream>
# include <cmath>
# include <climits>
# include <map>

// -MACROS-
# ifndef NULL
#  define NULL 0
# endif
// colours
# define GREY		"\001\033[1;37m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define RED		"\001\033[1;31m\002"
# define R			"\001\033[1;00m\002"

// -CLASS-
class BitcoinExchange
{
	public:
		BitcoinExchange(std::fstream &csvfile);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &src);

		void 		printRes(std::string row);
		std::string	validDate(std::istringstream &iss, char sep);
		float		validFloat(std::istringstream &iss);
		float		findEntry(std::string key);

		bool		checkDate(int year, int month, int day);
		std::string	trim(std::string str, char c);

	private:
		BitcoinExchange();
		std::map<std::string, float> _csv_map;

};

#endif
