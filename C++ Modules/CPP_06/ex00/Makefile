# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 11:53:50 by cbouvet           #+#    #+#              #
#    Updated: 2025/02/08 18:44:34 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
CXX = @c++
CXX_FLAGS = -Werror -Wextra -Wall -std=c++98
SRC = 	main.cpp \
		ScalarConverter.cpp \
		CharType.cpp	IntType.cpp	\
		DoubleType.cpp	FloatType.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo convert is ready!

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	rm -f $(NAME)
	@echo convert destroyed!

re: fclean all

.PHONY: all clean fclean re
