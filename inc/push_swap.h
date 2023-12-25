/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:08:44 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 03:38:57 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <unistd.h>

# include "stack.h"

typedef struct s_info
{
	int	size_a;
	int	size_b;
}		t_info;

/* algorithm.c */
void    sort_3(t_stack **stack);
void    sort_5(t_stack **a, t_stack **b, t_info *info);
void    push_swap(t_stack **a, t_stack **b, t_info *info);

/* parser.c */
int		choose_state(int state, char c);
void	parser(int argc, char **argv);

/* create_stack.c */
void	create_stack(t_stack **stack_a, t_info *info, char **argv);

/* moves.c */
void	push(char c, t_stack **dest, t_stack **src, t_info *info);
void	swap(t_stack **stack, char c);
void	rotate(t_stack **stack, char c);
void	rrotate(t_stack **stack, char c);

void	double_swap(t_stack **stack);
void	double_rotate(t_stack **stack);
void	double_rrotate(t_stack **stack);

/* tools.c */
void	print_error(char *str);
void	write_move(char *move, char type);

#endif
