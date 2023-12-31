/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:03:14 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/01 00:06:12 by psegura-         ###   ########.fr       */
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
	second->prev = NULL;
	if ((*stack)->next)
		(*stack)->next->prev = *stack;
	(*stack)->prev = second;
	*stack = second;
	if (c == 'a' || c == 'b')
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
	if (*dest)
		(*dest)->prev = aux;
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
	last->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = last;
	*stack = new_head;
	if (new_head)
		new_head->prev = NULL;
	if (c == 'a' || c == 'b')
		write_move("r", c);
}

void	rrotate(t_stack **stack, char c)
{
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	if (c == 'a' || c == 'b')
		write_move("rr", c);
}
