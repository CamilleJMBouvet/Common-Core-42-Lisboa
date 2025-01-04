# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 14:17:33 by cbouvet           #+#    #+#              #
#    Updated: 2024/07/20 14:27:18 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maggots
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp	Bureaucrat.cpp	Form.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo maggots is ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo maggots destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
