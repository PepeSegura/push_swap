/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:03:14 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/24 23:49:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack **stack)
{
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
	write_move("s", 's');
}

void	double_rotate(t_stack **stack)
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
	write_move("r", 'r');
}

void	double_rrotate(t_stack **stack)
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
	write_move("rr", 'r');
}
