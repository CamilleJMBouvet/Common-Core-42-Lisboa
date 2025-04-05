# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 23:07:22 by cbouvet           #+#    #+#              #
#    Updated: 2025/01/18 20:28:41 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Serializer.cpp	main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo serialize is ready!

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	rm -f $(NAME)
	@echo serialize destroyed!

re: fclean all

.PHONY: all clean fclean re