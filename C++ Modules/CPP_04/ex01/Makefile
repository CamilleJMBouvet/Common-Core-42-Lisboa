# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 16:02:47 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/30 17:05:15 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = world_on_fire
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		Animal.cpp		Dog.cpp			Cat.cpp \
		Brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo world_on_fire is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo world_on_fire destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
