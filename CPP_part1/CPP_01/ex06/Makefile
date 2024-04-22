# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 19:34:58 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/22 15:51:04 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl_filter
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp	Harl.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo harl_filter is ready!
	@$(CXX) $(CXX_FILTER) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo harl_filter destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
