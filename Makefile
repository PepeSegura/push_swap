# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2023/12/31 20:42:17 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = push_swap
BONUS = checker

SRCS =									\
		main.c							\
		tools.c							\
		parser/parser.c					\
										\
		stack/create_stack.c			\
		stack/stack_add_back.c			\
		stack/stack_printer.c			\
		stack/stack_last.c				\
		stack/stack_new.c				\
		stack/stack_size.c				\
										\
		algorithm/push_swap.c			\
		algorithm/basic/sort_3.c		\
		algorithm/basic/sort_5.c		\
		algorithm/chunks/chunks.c		\
		algorithm/chunks/chunks_utils.c	\
		algorithm/radix/radix.c			\
		algorithm/utils.c				\
										\
		moves/single.c					\
		moves/double.c					\


SRCB =									\
		bonus/main.c					\
		tools.c							\
		parser/parser.c					\
										\
		stack/create_stack.c			\
		stack/stack_add_back.c			\
		stack/stack_last.c				\
		stack/stack_new.c				\
		stack/stack_size.c				\
										\
		moves/single.c					\
		moves/double.c					\
										\
		algorithm/utils.c				\

SRCS_PREFIX = $(addprefix srcs/, $(SRCS))
SRCB_PREFIX = $(addprefix srcs/, $(SRCB))

OBJS = $(SRCS_PREFIX:%.c=objs/%.o)
OBJB = $(SRCB_PREFIX:%.c=objsb/%.o)

LIB = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address,leak
CFLAGS += -I inc -I libft

all: $(NAME)
bonus: $(BONUS)

$(NAME): objs $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(BONUS): objsb $(OBJB)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJB) $(LIB) -o $(BONUS)

objs:
	@mkdir -p	objs/srcs/moves objs/srcs/parser objs/srcs/stack \
				objs/srcs/algorithm objs/srcs/bonus
	@mkdir -p 	objs/srcs/algorithm/basic objs/srcs/algorithm/chunks \
				objs/srcs/algorithm/radix objs/srcs/algorithm/best_cost

objsb:
	@mkdir -p	objsb/srcs/moves objsb/srcs/parser objsb/srcs/stack \
				objsb/srcs/algorithm objsb/srcs/bonus

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

objsb/%.o: %.c
	@$(CC) -D BONUS=1 $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf objs objsb

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) $(BONUS)

re:: fclean
re:: all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma bonus
