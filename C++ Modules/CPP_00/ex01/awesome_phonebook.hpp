/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:20:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/11 18:17:32 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_PHONEBOOK
# define AWESOME_PHONEBOOK

// -LIBRARIES-
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

// -MACROS-
# define PURPLE		"\001\033[1;38;2;209;174;231m\002"
# define BLUE		"\001\033[1;38;2;147;222;255m\002"
# define PINK		"\001\033[1;38;5;225m\002"
# define WHITE		"\001\033[1;37m\002"
# define RED		"\001\033[0;31m\002"
# define R			"\001\033[1;00m\002"

// -FUNCTIONS-
Contact	create_contact(void);

#endif
