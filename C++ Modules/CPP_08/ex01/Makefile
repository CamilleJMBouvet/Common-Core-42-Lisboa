# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 22:35:14 by cbouvet           #+#    #+#              #
#    Updated: 2025/02/15 20:39:32 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Span.cpp	main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo span is ready!

%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	@rm -f $(NAME)
	@echo span destroyed!

re: fclean all

.PHONY: all clean fclean re
