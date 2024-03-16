/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/17 00:43:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_index_to_top(t_stack **a, t_info *info)
{
	const t_stack	*stack_aux = *a;
	int				pos;

	pos = 0;
	while (stack_aux)
	{
		if (stack_aux->index == 0)
			break ;
		pos++;
		stack_aux = stack_aux->next;
	}
	if (pos < info->size_a / 2)
	{
		while (pos-- > 0)
			rotate(a, 'a');
	}
	else
	{
		pos = info->size_a - pos;
		while (pos-- > 0)
			rrotate(a, 'a');
	}
}

void	move_max_index_to_top(t_stack **b, t_info *info)
{
	const t_stack	*stack_aux = *b;
	int				pos;

	pos = 0;
	while (stack_aux)
	{
		if (stack_aux->index == (info->size_b - 1))
			break ;
		pos++;
		stack_aux = stack_aux->next;
	}
	if (pos < info->size_b / 2)
	{
		while (pos-- > 0)
			rotate(b, 'b');
	}
	else
	{
		pos = info->size_b - pos;
		while (pos-- > 0)
			rrotate(b, 'b');
	}
}

void	push_two_chunks(t_stack **a, t_stack **b, t_info *info, int chunk_limit)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = info->size_a;
	while (i < size)
	{
		if ((*a)->index < chunk_limit)
			push('b', b, a, info);
		else if ((*a)->index > (info->size_a - chunk_limit))
		{
			push('b', b, a, info);
			rotate(b, 'b');
		}
		else
			rotate(a, 'a');
		if (info->size_a <= 3)
			break ;
		i++;
	}
}

void	turk_chunks(t_stack **a, t_stack **b, t_info *info, size_t chunk_size)
{
	int	i;

	i = 1;
	while (info->size_a > 3)
	{
		push_two_chunks(a, b, info, chunk_size * i);
		i++;
	}
	sort_3(a);
	while (info->size_b > 0)
		move_cheapest_b_to_a(b, a, info);
	move_min_index_to_top(a, info);
}

void	best_cost(t_stack **a, t_stack **b, t_info *info)
{
	push('b', b, a, info);
	push('b', b, a, info);
	while (info->size_a > 0)
		move_cheapest_a_to_b(a, b, info);
	move_max_index_to_top(b, info);
	while (info->size_b > 0)
		push('a', a, b, info);
	move_min_index_to_top(a, info);
}
