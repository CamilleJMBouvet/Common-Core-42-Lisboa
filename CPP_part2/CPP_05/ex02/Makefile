# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 16:11:31 by cbouvet           #+#    #+#              #
#    Updated: 2024/11/08 21:33:46 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form_28b
CXX = @c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC =	main.cpp \
		AForm.cpp	Bureaucrat.cpp	\
		ShrubberyCreationForm.cpp	RobotomyRequestForm.cpp	PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo form_28b is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo form_28b destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
