/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:00:18 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/11 19:46:02 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// -LIBRARIES-
# include "Form.hpp"
# include <fstream>

// -MACROS-
#define TREE "    ccee88oo\n \
 C8O8O8Q8PoOb o8oo\n \
dOB69QO8PdUOpugoO9bD\n \
CgggbU8OU qOp qOdoUOdcb\n \
    6OuU  /p u gcoUodpP\n \
      \\\\//  /douUP\n \
        \\\\\\////\n \
         |||/\\\n \
         |||\\/\n \
         |||||\n \
   .....//||||\\...."

// -CLASS-
class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);

		std::string	getTarget()const;

	protected:
		void	executeAction()const;

	private:
		std::string _target;
		ShrubberyCreationForm();
};

#endif
