# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 19:00:40 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/29 20:09:37 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphism
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		Animal.cpp			Dog.cpp			Cat.cpp \
		WrongAnimal.cpp		WrongCat.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo polymorphism is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo polymosphism destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
