# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 17:27:24 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/12 14:41:43 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dream_job
CPP_C = @g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Account.cpp	tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo dream_job ready!
	$(CPP_C) $(CPP_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo dream_job destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
