/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:54:52 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/11 16:28:33 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2 )
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; av[i]; i++)
		for (int j = 0; av[i][j]; j++)
			av[i][j] = std::toupper(av[i][j]);
	for (int i = 1; i < ac; i++)
		std::cout << av[i];
	std::cout << std::endl;
	return (0);
}
