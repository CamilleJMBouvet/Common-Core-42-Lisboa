# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 20:22:59 by cbouvet           #+#    #+#              #
#    Updated: 2025/01/22 12:11:22 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realtype
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	Base.cpp \
		A.cpp	B.cpp	C.cpp \
		main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo realtype is ready!

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	rm -f $(NAME)
	@echo realtype destroyed!

re: fclean all

.PHONY: all clean fclean re
