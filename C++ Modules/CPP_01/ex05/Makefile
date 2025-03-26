# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 18:00:40 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/20 19:25:44 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp	Harl.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo harl is ready!
	@$(CXX) $(CXX_fLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo harl destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
