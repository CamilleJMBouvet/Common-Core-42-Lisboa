# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 16:20:27 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/24 17:30:24 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = canonical
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp	Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo canonical is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo canonical destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
