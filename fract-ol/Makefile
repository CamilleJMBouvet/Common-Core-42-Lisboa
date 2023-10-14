# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 14:21:06 by cbouvet           #+#    #+#              #
#    Updated: 2023/10/10 17:42:56 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	src/main.c \
		src/arg_handling.c src/init.c \
		src/win_handling.c src/sets.c src/hooks.c\
		src/utils.c
OBJ = $(SRC:.c=.o)
LIBFT =	libft/libft.a

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@echo fract-ol compiled!
	@make -sC libft
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

clean:
	@echo fract-ol .o files removed!
	@rm -f $(OBJ)
	@make clean -sC libft/

fclean: clean
	@echo fract-ol is clean!
	@rm -f $(NAME)
	@make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re
