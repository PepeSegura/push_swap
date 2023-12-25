/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:52:24 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 01:35:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

typedef struct s_stack {
	int				index;
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int content);
t_stack	*stack_last(t_stack *stack);

void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);

void	stack_clear(t_stack **stack);
void	stack_delone(t_stack *stack);

int		stack_size(t_stack *stack);

void	print_stack(t_stack *stack);

#endif
