/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:03:14 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/24 23:49:21 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
	write_move("s", c);
}

void	push(char c, t_stack **dest, t_stack **src, t_info *info)
{
	t_stack	*aux;

	if (*src == NULL)
		return ;
	aux = *src;
	*src = (*src)->next;
	aux->next = *dest;
	*dest = aux;
	if (c == 'a')
	{
		info->size_a++;
		info->size_b--;
	}
	if (c == 'b')
	{
		info->size_b++;
		info->size_a--;
	}
	write_move("p", c);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*new_head;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new_head = (*stack)->next;
	last = stack_last(*stack);
	// while (last->next != NULL)
	// 	last = last->next;
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = new_head;
	write_move("r", c);
}

void	rrotate(t_stack **stack, char c)
{
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = stack_last(*stack);
	// while (last->next != NULL)
	// 	last = last->next;
	last->next = *stack;
	*stack = last->next;
	last->next = NULL;
	write_move("rr", c);
}
