# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2023/12/25 03:39:24 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = push_swap

SRCS =									\
		srcs/main.c						\
		srcs/tools.c					\
		srcs/parser/parser.c			\
										\
		srcs/stack/create_stack.c		\
		srcs/stack/stack_add_back.c		\
		srcs/stack/stack_add_front.c	\
		srcs/stack/stack_clear.c		\
		srcs/stack/stack_printer.c		\
		srcs/stack/stack_last.c			\
		srcs/stack/stack_new.c			\
		srcs/stack/stack_size.c			\
										\
		srcs/algorithm/push_swap.c		\
		srcs/algorithm/sort_3.c			\
		srcs/algorithm/sort_5.c			\
		srcs/algorithm/utils.c			\
										\
		srcs/moves/single.c				\
		srcs/moves/double.c				\


OBJS = $(SRCS:%.c=objs/%.o)

LIB = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address,leak
CFLAGS += -I inc -I libft


$(NAME): objs $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

objs:
	@mkdir -p	objs/srcs/moves		objs/srcs/parser	objs/srcs/stack	\
				objs/srcs/algorithm

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf objs

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re:: fclean
re:: all

.PHONY: all clean fclean re
