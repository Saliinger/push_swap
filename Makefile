# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 14:36:40 by anoukan           #+#    #+#              #
#    Updated: 2024/05/29 17:16:56 by anoukan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils
FONCTION_DIR = $(SRC_DIR)/functions
INIT_DIR = $(SRC_DIR)/init
SORT_DIR = $(SRC_DIR)/sort

# List all source files
FUNCTION = $(wildcard $(FONCTION_DIR)/*.c)
UTILS = $(wildcard $(UTILS_DIR)/*.c)
SRC = $(wildcard $(SRC_DIR)/*.c)
INIT = $(wildcard $(INIT_DIR)/*.c)
SORT = $(wildcard $(SORT_DIR)/*.c)

# Generate object file paths for all source files
OBJ_SRC = $(SRC:%.c=%.o)
OBJ_FUNCTION = $(FUNCTION:%.c=%.o)
OBJ_UTILS = $(UTILS:%.c=%.o)
OBJ_SORT = $(SORT:%.c=%.o)
OBJ_INIT = $(INIT:%.c=%.o)

# Combine object files from all sources
OBJ = $(OBJ_SRC) $(OBJ_FUNCTION) $(OBJ_UTILS) $(OBJ_INIT) $(OBJ_SORT)

# Compilation flags
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Library flags
LIBS = -L./libft/ -lft

.PHONY: all clean fclean re lib

all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

lib:
	@echo "Compiling in libft"
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all
