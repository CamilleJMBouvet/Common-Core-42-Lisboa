# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:08:13 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/18 17:13:15 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sifl
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo sifl is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo sifl destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
