# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 17:08:28 by cbouvet           #+#    #+#              #
#    Updated: 2025/03/08 17:13:09 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp	RPN.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo RPN compiled!

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	rm -f $(NAME)
	@echo RPN destroyed!

re: fclean all

.PHONY: all clean fclean re