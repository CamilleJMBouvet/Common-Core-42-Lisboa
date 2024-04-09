# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 20:03:35 by cbouvet           #+#    #+#              #
#    Updated: 2024/04/05 22:21:22 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = @cc
CFLAGS = -Wall -Werror -Wextra -g -pthread #-fsanitize=thread
SRC = 	src/main.c			src/param_check.c \
		src/init_var.c		src/init_structs.c \
		src/routine.c		src/utils.c \
		src/clean_exit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo philo compiled!
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lrt

clean:
	@echo .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo philo is clean!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
