# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 21:18:11 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/14 22:06:33 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz
CXX = @c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = 	main.cpp \
		Zombie.cpp	newZombie.cpp	randomChump.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo brainz ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo brainz destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
