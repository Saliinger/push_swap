# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 14:36:40 by anoukan           #+#    #+#              #
#    Updated: 2024/06/04 14:46:38 by anoukan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap

SRCS = src/functions/r.c \
		src/functions/rr.c \
		src/functions/s.c \
		src/functions/p.c \
		src/init/cheapest_init.c \
		src/init/init_a.c \
		src/init/init_b.c \
		src/init/target_a_init.c \
		src/init/median_init.c \
		src/init/target_b_init.c \
		src/init/index_init.c \
		src/init/ft_check.c \
		src/init/push_cost_init.c \
		src/init/init.c \
		src/sort/a_b.c \
		src/sort/b_a.c \
		src/sort/3_sort.c \
		src/sort/is_sorted.c \
		src/sort/get_cheapest.c \
		src/sort/sort.c \
		src/utils/t_list.c \
		src/utils/utils.c \
		src/push_swap.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	$(CC) ${FLAGS} -c $< -o $(<:.c=.o)

# Compilation flags
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Library flags
LIBS = -L./libft/ -lft

.PHONY: all clean fclean re lib

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBS)

lib:
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all
