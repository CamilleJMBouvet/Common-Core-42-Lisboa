# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:27:39 by cbouvet           #+#    #+#              #
#    Updated: 2024/03/26 14:34:31 by gverissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Temporary Makefile just to ease the compiling

NAME = minishell
CC = @cc

CFLAGS = -Wall -Wextra -Werror -g
SRC = 	main.c \
		shell_handler/signals.c		shell_handler/shell_start.c		shell_handler/basic_vars.c \
		shell_handler/set_env.c		shell_handler/dlist_handler.c	shell_handler/hist_n_export.c	\
		shell_handler/reboot.c		shell_handler/clean_all.c \
		tokenizer/token_handler.c	tokenizer/tokenizer.c			tokenizer/expansions.c \
		tokenizer/utils.c \
		ast/ast_builder.c			ast/redir_node.c				ast/open_fds.c \
		ast/utils.c \
		executer/executer.c			executer/cmd_exec.c				executer/builtin_exec.c \
		executer/builtin_echo.c		executer/builtin_cd.c			executer/builtin_export.c \
		executer/builtin_pwd.c		executer/builtin_unset.c		executer/builtin_env.c \
		executer/builtin_exit.c		executer/utils.c \

OBJ = $(SRC:.c=.o)
VALGRIND="valgrind"
LIBFT = libft/libft.a


all: $(NAME)

$(NAME): $(OBJ)
	@echo minishell compiled
	@make -sC libft

	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline


clean:
	@echo .o files removed
	@rm -f $(OBJ) readline.supp
	@make clean -sC libft/

fclean: clean
	@echo minishell cleared up
	@rm -f $(NAME)
	@make fclean -sC libft/

re: fclean all

readline.supp:
	@wget https://raw.githubusercontent.com/benjaminbrassart/minishell/master/readline.supp

valgrind: $(NAME) readline.supp
	@/usr/bin/valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./$(NAME) $(VALGRIND)
valgrind_i: $(NAME) readline.supp
	@/usr/bin/valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp env -i ./$(NAME) $(VALGRIND)

.PHONY: all clean fclean re
