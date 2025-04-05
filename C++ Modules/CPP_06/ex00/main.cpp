/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:59:11 by cbouvet           #+#    #+#             */
/*   Updated: 2025/02/08 18:35:52 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -LIBRARIES-
#include <iostream>
#include "ScalarConverter.hpp"

// -FUNCTIONS-
int main(int ac, char **av)
{
	if (ac >= 2 && av[1][0])
		ScalarConverter::convert(av[1]);
	else
		std::cout << RED "Error! Use format: './convert' followed by a string formatted to char, int, float or double" R << std::endl;
}
