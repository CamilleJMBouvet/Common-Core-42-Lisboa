# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 17:10:26 by cbouvet           #+#    #+#              #
#    Updated: 2023/10/29 21:50:32 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	src/main.c \
		src/init_struct.c src/clean_exit.c src/cmd_exec.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo pipex compiled!
	@make -sC libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@echo pipex .o files removed!
	@rm -f $(OBJ)
	@make clean -sC libft/

fclean: clean
	@echo pipex is clean!
	@rm -f $(NAME)
	@make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re
