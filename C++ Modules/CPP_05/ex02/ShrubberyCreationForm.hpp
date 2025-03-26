/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:11:15 by cbouvet           #+#    #+#             */
/*   Updated: 2024/11/10 22:41:51 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// -LIBRARIES-
# include <fstream>
# include "AForm.hpp"

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
class ShrubberyCreationForm: public AForm
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
		std::string	_target;
		ShrubberyCreationForm();
};

#endif
