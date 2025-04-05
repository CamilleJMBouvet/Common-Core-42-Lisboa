# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 18:52:03 by cbouvet           #+#    #+#              #
#    Updated: 2025/03/18 17:18:56 by cbouvet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CXX = @c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp	PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJ)
	@echo PmergeMe compiled!

%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo .o files removed!

fclean: clean
	@rm -f $(NAME)
	@echo PmergeMe destroyed!

re: fclean all

.PHONY: all clean fclean re
