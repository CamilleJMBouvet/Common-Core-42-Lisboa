/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sifl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:50:08 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/20 17:52:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIFL_HPP
# define SIFL_HPP

// - LIBRARIES -
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// - MACROS -
# define RED		"\001\033[0;31m\002"
# define R			"\001\033[1;00m\002"

// - FUNCTIONS -
int		error_manager(int ac, char **av, std::ios *fd);
void	replace(std::ifstream &ifs, std::ofstream &ofs, char **av);

#endif
