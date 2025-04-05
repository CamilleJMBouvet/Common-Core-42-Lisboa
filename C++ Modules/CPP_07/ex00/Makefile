# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 17:55:29 by cbouvet           #+#    #+#              #
#    Updated: 2025/01/30 23:51:36 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = swapminmax
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo swapminmax is ready!

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	rm -f $(NAME)
	@echo swapminmax destroyed!

re: fclean all

.PHONY: all clean fclean re
