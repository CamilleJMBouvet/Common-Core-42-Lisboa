/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:08:16 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/20 17:59:51 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sifl.hpp"

int	main(int ac, char **av)
{
	if (error_manager(ac, av, NULL))
		return (1);

	std::ifstream	ifs(av[1]);
	if (error_manager(0, NULL, &ifs))
		return (2);

	std::string outfile = std::string(av[1]) + ".replace";
	std::ofstream	ofs(outfile);
	if (error_manager(0, NULL, &ofs))
		return (2);

	replace(ifs, ofs, av);

	ifs.close();
	ofs.close();
}

// Checks errors + prints messages
int	error_manager(int ac, char **av, std::ios *fd)
{
	std::string err;

	if (ac && ac != 4)
		err = "Incorrect number of parameters";
	if (av)
		for (int i = 1; av[i]; i++)
			if (!av[i][0])
				err = "Empty parameter";
	if (fd && !fd->good())
		err = std::strerror(errno);

	if (!err.empty())
		std::cerr << RED "Error: " << err << R << std::endl;

	return (err.size());
}

// Replaces av[2] by av[1]
void	replace(std::ifstream &ifs, std::ofstream &ofs, char **av)
{
	std::string buff;

	while (std::getline(ifs, buff))
	{
		size_t i = 0;
		size_t	position = 0;
		while (i < buff.size() && position < buff.size())
		{
			position = buff.find(av[2], i);
			if (position == std::string::npos)
				break ;
			ofs << buff.substr(i, position - i) << av[3];
			i += (position - i) + std::strlen(av[2]);
		}
		if (i < buff.size())
			ofs << &buff[i];
		ofs << std::endl;
		buff = "";
	}
}
