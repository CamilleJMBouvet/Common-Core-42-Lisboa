# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 14:40:13 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/15 14:55:06 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hi_brain
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo hi_brain ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo hi_brain destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
