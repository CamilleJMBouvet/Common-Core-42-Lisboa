# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 22:50:20 by cbouvet           #+#    #+#              #
#    Updated: 2025/02/08 13:04:36 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo array is ready!

%.o:%.cpp
	@$(CXX) $(CXX_fLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	rm -f $(NAME)
	@echo array destroyed!

re: fclean all

.PHONY: all clean fclean re


