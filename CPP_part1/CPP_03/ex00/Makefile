# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 22:01:59 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/26 22:06:59 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp	ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo claptrap is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo claptrap destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
