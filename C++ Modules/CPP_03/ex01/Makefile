# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:41:59 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/27 17:45:40 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp	ClapTrap.cpp	ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo scavtrap is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo scavtrap destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
