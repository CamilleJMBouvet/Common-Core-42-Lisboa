# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 23:03:48 by cbouvet           #+#    #+#              #
#    Updated: 2025/02/11 23:53:12 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyway
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo easyway is ready!

%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	@rm -f $(NAME)
	@echo easyway removed!

re: fclean all

.PHONY: all clean fclean re
