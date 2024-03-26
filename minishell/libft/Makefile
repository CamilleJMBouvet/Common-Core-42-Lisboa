# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 17:01:19 by cbouvet           #+#    #+#              #
#    Updated: 2024/03/06 20:44:00 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = @cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	memory_functions/ft_bzero.c memory_functions/ft_calloc.c memory_functions/ft_memchr.c \
		memory_functions/ft_memcmp.c memory_functions/ft_memcpy.c memory_functions/ft_memmove.c \
		memory_functions/ft_memset.c \
		char_functions/ft_isalnum.c char_functions/ft_isalpha.c char_functions/ft_isascii.c \
		char_functions/ft_isdigit.c char_functions/ft_isprint.c char_functions/ft_tolower.c \
		char_functions/ft_toupper.c \
		string_functions/ft_split.c string_functions/ft_strrchr.c string_functions/ft_strdup.c \
		string_functions/ft_striteri.c string_functions/ft_strjoin.c string_functions/ft_strlcat.c \
		string_functions/ft_strlcpy.c string_functions/ft_strlen.c string_functions/ft_strmapi.c \
		string_functions/ft_strncmp.c string_functions/ft_strnstr.c string_functions/ft_strchr.c \
		string_functions/ft_strtrim.c string_functions/ft_substr.c \
		fd_functions/ft_putchar_fd.c fd_functions/ft_putendl_fd.c fd_functions/ft_putnbr_fd.c \
		fd_functions/ft_putstr_fd.c \
		digit_functions/ft_atoi.c digit_functions/ft_itoa.c \
		list_functions/ft_lstadd_back.c list_functions/ft_lstadd_front.c list_functions/ft_lstclear.c \
		list_functions/ft_lstdelone.c list_functions/ft_lstiter.c list_functions/ft_lstlast.c \
		list_functions/ft_lstmap.c list_functions/ft_lstnew.c list_functions/ft_lstsize.c \
		fd_printf/fd_printf.c fd_printf/fd_printf_formats.c fd_printf/fd_printf_utils.c \
		get_next_line/get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo libft.a compiled!
	@ar -crs $(NAME) $(OBJ)

clean:
	@echo Libft .o files removed!
	@rm -f $(OBJ)

fclean: clean
	@echo Libft is clean!
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
