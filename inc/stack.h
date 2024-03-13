/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:52:24 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/13 22:07:19 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

typedef struct s_stack {
	int				index;
	int				content;

	/*  Algorithm */
	int				pos; //pos_in_stack
	int				target;
	int				dist_a;
	int				dist_b;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int content);
t_stack	*stack_last(t_stack *stack);
void	print_data(t_stack node);
void	stack_iteri(t_stack *stack, void(*f)(t_stack));

void	stack_add_back(t_stack **stack, t_stack *new);

void	stack_delone(t_stack *stack);

int		stack_size(t_stack *stack);

void	print_stack_content(t_stack *stack);
void	print_stack_index(t_stack *stack);

int		is_ordered(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_number(t_stack *stack, int number);

int		find_top_chunk(t_stack *stack, int max);
int		find_bottom_chunk(t_stack *stack, int max);

#endif
