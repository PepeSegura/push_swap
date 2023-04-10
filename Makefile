# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2023/04/10 17:24:18 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =							\
		srcs/create_stacks.c	\
		srcs/main.c				\
		srcs/moves_a.c			\
		srcs/moves_b.c			\
		srcs/moves_ab.c			\
		srcs/nbr_count.c		\
		srcs/parser.c			\
		srcs/sort_list.c		\
		srcs/tab_utils.c		\
		srcs/tools.c			\
		srcs/utils.c			\

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = clang
CFLAGS =  -Wall -Wextra -Werror -I inc -I libft -g3

$(NAME): $(OBJS)
	@make -C libft
	@rm -rf $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "📈 push_swap Done 📉"
	
all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@rm -rf $(OBJSB)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norm:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

normall: norm
	@echo 6e6f726d696e6574746520313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465203b20656c7365206e6f726d696e65747465207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norm normall

# rm -f normok; norminette 1>/dev/null; if [[ $? -eq 0 ]]; then echo "OK" > normok ; else norminette | grep 'Error' ; fi
