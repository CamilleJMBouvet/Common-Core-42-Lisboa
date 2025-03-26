# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 17:24:47 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/11 18:51:00 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CPP_C = @g++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = PhoneBook.cpp		Contact.cpp		main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Phonebook ready!
	$(CPP_C) $(CPP_FLAGS) -o $(NAME) $(OBJ)

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo phonebook destroyed!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

