/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/26 23:10:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	is_ordered(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !stack->next)
		return (1);
	first = stack;
	second = stack->next;
	while (second)
	{
		if (first->index > second->index)
			return (0);
		first = second;
		second = second->next;
	}	
	return (1);
}

int	find_min(t_stack *stack)
{
	t_stack	*current;
	int		min;

	if (!stack)
		return (0);
	if (!stack->next)
		return (stack->index);
	current = stack;
	min = current->index;
	while (current->next)
	{
		if (current->next->index < min)
			min = current->next->index;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_stack	*current;
	int		max;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	current = stack;
	max = current->index;
	while (current->next)
	{
		if (current->next->index > max)
			max = current->next->index;
		current = current->next;
	}
	return (max);
}

int	find_number(t_stack *stack, int number)
{
	// ft_dprintf(2,  "Buscando %d\n", number);
	t_stack	*current;
	int		index;

	current = stack;
	index = 0;
	while (current)
	{
		if (current->index == number)
			return (index);
		current = current->next;
		index++;
	}
	return (index);
}

int	find_top_chunk(t_stack *stack, int max)
{
	t_stack	*current;
	int		moves;

	current = stack;
	moves = 0;
	while (current)
	{
		// printf("TOP IX: %d MAX: %d\n", current->index, max);
		if (current->index < max)
		{
			// printf("max: %d index_top: %d\n", max, current->index);
			return (moves);
		}
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
		// printf("BOT IX: %d MAX: %d\n", current->index, max);
		if (current->index < max)
		{
			// printf("max: %d index_bot: %d\n", max, current->index);
			return (moves + 1);
		}
		current = current->prev;
		moves++;
	}
	return (moves + 1);
}

int numbers_in_chunk(t_stack *stack, int start, int end)
{
    while (stack)
	{
        if (stack->index >= start && stack->index < end)
            return (1);
        stack = stack->next;
    }
    return (0);
}
