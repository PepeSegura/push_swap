/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 19:50:12 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/04 03:01:26 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numbers_in_chunk(t_stack *stack, int start, int end)
{
	while (stack)
	{
		if (stack->index >= start && stack->index < end)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_current_greater_than_b(t_stack *a, t_stack *b)
{
	int	current;

	current = a->index;
	while (b != NULL)
	{
		if (current > b->index)
			return (1);
		b = b->next;
	}
	return (0);
}

int	find_top_chunk(t_stack *stack, int max)
{
	t_stack	*current;
	int		moves;

	current = stack;
	moves = 0;
	while (current)
	{
		if (current->index <= max)
			return (moves);
		current = current->next;
		moves++;
	}
	return (moves);
}

int	find_bottom_chunk(t_stack *stack, int max)
{
	t_stack	*current;
	int		moves;

	current = stack_last(stack);
	moves = 0;
	while (current)
	{
		if (current->index <= max)
			return (moves + 1);
		current = current->prev;
		moves++;
	}
	return (moves + 1);
}
