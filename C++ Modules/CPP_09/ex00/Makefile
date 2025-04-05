# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 20:20:11 by cbouvet           #+#    #+#              #
#    Updated: 2025/03/05 14:00:00 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp	BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo btc is ready!

%.o:%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	@rm -f $(NAME)
	@echo btc destroyed!

re: fclean all

.PHONY: all clean fclean re
