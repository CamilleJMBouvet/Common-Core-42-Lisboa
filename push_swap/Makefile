# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 14:02:34 by cbouvet           #+#    #+#              #
#    Updated: 2023/09/18 17:37:19 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	main.c \
		algorithm/algo.c algorithm/algo_tools.c algorithm/more_algo_tools.c\
		init_parsing_error/fill_stack.c init_parsing_error/init_val.c init_parsing_error/error_checks.c \
		operations/push_op.c operations/revrot_op.c operations/rot_op.c operations/swap_op.c \
		other_tools/node_handling.c other_tools/sorted_arr.c other_tools/stack_tools.c
OBJ = $(SRC:.c=.o)
LIBFT =	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo push_swap compiled!
	@make -sC libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@echo push_swap .o files removed!
	@rm -f $(OBJ)
	@make clean -sC libft/

fclean: clean
	@echo push_swap is clean!
	@rm -f $(NAME)
	@make fclean -sC libft/

re: fclean all

.PHONY: all clean fclean re
