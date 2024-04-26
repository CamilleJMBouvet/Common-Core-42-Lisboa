# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 23:27:49 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/24 17:31:02 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = useful_fixpt
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp	Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo useful_fixpt is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo udeful_fixpt destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
