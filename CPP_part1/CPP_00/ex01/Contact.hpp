/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:25:08 by cbouvet           #+#    #+#             */
/*   Updated: 2024/04/11 14:40:40 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:

	char 	msg[6][18] = {"first name: \0", "last name: \0", \
	"nickname: \0", "phone number: \0", "darkest secret: \0", {0}};

		Contact(void);
		~Contact(void);

		char	*get_fields(int index);
		bool	set_fields(int index, std::string buff);

	private:
		char	_fields[5][50];
};

#endif
