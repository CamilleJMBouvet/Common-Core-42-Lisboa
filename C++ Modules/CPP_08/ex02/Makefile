# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 20:27:52 by cbouvet           #+#    #+#              #
#    Updated: 2025/02/18 17:32:12 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutated_abomination
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo mutated_abomination is ready!

%.o:%.cpp
	@$(CXX) $(CXX_fLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	@rm -f $(NAME)
	@echo mutated_abomination destroyed!

re: fclean all

.PHONY: all clean fclean re
