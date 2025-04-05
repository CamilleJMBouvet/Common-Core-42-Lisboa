/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:24:14 by cbouvet           #+#    #+#             */
/*   Updated: 2025/03/15 20:12:50 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include "BitcoinExchange.hpp"

//----------------- Constructor/Destructor -----------------
BitcoinExchange::BitcoinExchange()
{
	throw (std::runtime_error("Forbidden constructor"));
}

BitcoinExchange::BitcoinExchange(std::fstream &csvfile)
{
	std::string buff;
	if (!getline(csvfile, buff))
        throw std::runtime_error("CSV file empty, nothing to do");
	
	while (getline(csvfile, buff))
	{
		std::istringstream iss(buff);
		try
		{
			std::string key = validDate(iss, ',');
			float value = validFloat(iss);
			this->_csv_map[key] = value;
		}
		catch (std::exception &e)
		{
			std::cerr << RED "ERROR: " << e.what() << std::endl;
			std::cerr << GREY "entry will be dismissed from database" R << std::endl;
		}
	}
	
	if (this->_csv_map.empty())
        throw std::runtime_error("no entry found on CSV, nothing to do");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->_csv_map = src._csv_map;
}

BitcoinExchange::~BitcoinExchange()
{}

//---------------- Copy assignement operator ---------------
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_csv_map = src._csv_map;
	return (*this);
}

//-------------------- Action functions --------------------
void 	BitcoinExchange::printRes(std::string row)
{
	std::istringstream iss(row);

	try
	{
		std::string key = validDate(iss, '|');
		float value = validFloat(iss);
		float res = this->findEntry(key) * value;
		std::cout << GREY << key << " => " GREY << value \
				  << GREY " = " PINK << res << R << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << RED "ERROR: " << e.what() << R << std::endl;
	}
}

std::string	BitcoinExchange::validDate(std::istringstream &iss, char sep)
{
	std::string str;
	if (!getline(iss, str, sep))
		throw (std::runtime_error("empty input"));

	std::string err = "bad input => " + str;
	str = this->trim(str, ' ');
	if (str.size() != 10 || str[4] != '-' || str[7] != '-')
		throw (std::runtime_error(err));
	
	std::string date[3] = {str.substr(0, 4), str.substr(5, 2), str.substr(8, 2)};
	for (int i = 0; i < 3; i++)
		if (date[i].find_first_not_of("0123456789") != date[i].npos)
			throw (std::runtime_error(err));
	
	if (!this->checkDate(atoi(date[0].c_str()), atoi(date[1].c_str()), atoi(date[2].c_str())))
		throw (std::runtime_error(err));
	
	return (str);
}

float	BitcoinExchange::validFloat(std::istringstream &iss)
{
	std::string str;
	if (!getline(iss, str))
		throw (std::runtime_error("empty input"));

	char *end = NULL;
	str = this->trim(str, ' ');
	double d = strtod(str.c_str(), &end);
	std::string err = "bad input => " + str;

	if (end == str.c_str() || *end != 0 || (!d && str.compare("0") && str.compare("-0")) || std::isnan(d))
		throw (std::runtime_error(err));
	if (d < 0 )
		throw (std::runtime_error("not a positive number"));
	if (d > INT_MAX || str.size() > 10)
		throw (std::runtime_error("too large a number"));

	return (static_cast<float>(d));
}

float	BitcoinExchange::findEntry(std::string key)
{
	std::map<std::string, float>::iterator it = this->_csv_map.begin();
	
	if (key.compare(it->first) < 0)
		throw (std::runtime_error("input predates earliest rate registered"));
	
	it = --this->_csv_map.end();
	if (key.compare(it->first) > 0)
		return (it->second);

	it = this->_csv_map.find(key);
	if (it != this->_csv_map.end())
		return (it->second);
		
	it = this->_csv_map.lower_bound(key);
	--it;
		
	return (it->second);
}

//------------------------- Utils --------------------------
bool	BitcoinExchange::checkDate(int year, int month, int day)
{
	if ((year < 1 || year > 2025) || (month < 1 || month > 12) || day < 1 || day > 31)
		return (false);

	int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		month_days[2] = 29;

	if (day > month_days[month])
		return (false);
	
	return (true);
}

std::string	BitcoinExchange::trim(std::string str, char c)
{
	int i = 0;
	int j = str.size() -1;

	while (str[i] && str[i] == c)
		i++;
	while (j >= 0 && str[j] == c)
		j--;

	return (str.substr(i, j +1));
}

