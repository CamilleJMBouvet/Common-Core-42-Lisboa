# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 22:11:57 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/14 23:35:46 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moar_brainz
CXX = @c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = 	main.cpp \
		Zombie.cpp	zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo moar_brainz ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo moar_brainz destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
