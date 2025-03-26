# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:14:59 by cbouvet           #+#    #+#              #
#    Updated: 2024/05/01 18:22:02 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_class
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		AAnimal.cpp		Brain.cpp \
		Dog.cpp			Cat.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo abstract_class is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo abstract_class ready!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
