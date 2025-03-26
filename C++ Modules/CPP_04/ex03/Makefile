# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 18:30:57 by cbouvet           #+#    #+#              #
#    Updated: 2024/05/02 15:15:24 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interface_recap
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		AMateria.cpp \
		MateriaSource.cpp		Cure.cpp		Ice.cpp		Character.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo interface_recap is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo interface_recap destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
