/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:24:57 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/11 15:38:49 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

		Contact	indexes[8];

		PhoneBook(void);
		~PhoneBook(void);

		bool	add(Contact new_contact, int i);
		void	search(void);
		void	select_index(void);
		void	exit(void);
};

#endif
