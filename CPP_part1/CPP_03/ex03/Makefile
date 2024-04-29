# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 17:32:48 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/28 20:06:47 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamond
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		ClapTrap.cpp	ScavTrap.cpp	FragTrap.cpp	DiamondTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo diamond is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo diamond destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
