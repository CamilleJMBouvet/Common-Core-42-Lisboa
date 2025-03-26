# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:09:18 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/15 15:13:48 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unnecessary_violence
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		Weapon.cpp	HumanA.cpp	HumanB.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo unnecessary_violence ready!
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo unnecessary_violence destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
