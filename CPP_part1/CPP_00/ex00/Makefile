# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 14:54:55 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/08 17:00:30 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CPP_C = @g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Megaphone compiled!
	$(CPP_C) $(CPP_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo megaphone.o removed!
	@rm -f $(OBJ)

fclean: clean
	@echo megaphone is clean!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
