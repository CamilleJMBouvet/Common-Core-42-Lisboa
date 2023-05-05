# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 21:41:36 by cbouvet           #+#    #+#              #
#    Updated: 2023/05/05 19:15:22 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = ft_printf.c ft_printf_chr.c ft_printf_str.c ft_printf_ptr.c ft_printf_nbr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar -crs $(NAME) $(OBJ) $(LIBFT_DIR)/*.o

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
