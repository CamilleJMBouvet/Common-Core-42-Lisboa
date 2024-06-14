NAME = cub3D

CC = @cc

CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

SRC =	src/main.c \
		src/parser.c		src/data_parser.c	src/map_parser.c \
		src/data_utils.c	src/map_utils.c \
		src/init_player.c 	src/init_display.c \
		src/hooks_mvts.c \
		src/cub2d.c 		src/cub3d.c 		src/rendering.c \
		src/clean_exit.c

OBJ = $(SRC:.c=.o)

LIBFT = inc/libft/libft.a

MLX = inc/minilibx/libmlx.a

MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -O3

all: $(NAME)

$(MLX):
	@make -sC inc/minilibx

$(NAME): $(OBJ) $(MLX)
	@echo "\033[32m[success]\033[0m cub3D compiled!"
	@make -sC inc/libft
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
	@echo "\033[33m[clean]\033[0m cub3D object files removed!"
	@rm -f $(OBJ)
	@make clean -sC inc/libft/
	@make clean -sC inc/minilibx/

fclean: clean
	@echo "\033[31m[fclean]\033[0m cub3D executable file removed!"
	@rm -f $(NAME)
	@make fclean -sC inc/libft/

re: fclean all

.PHONY: all clean fclean re
