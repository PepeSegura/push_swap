/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/31 19:53:37 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_chunk_range(int *start, int *end, int numbers, int nb_chunks)
{
	if (*end + 1 >= numbers)
		return ;
	*start += numbers / nb_chunks;
	*end += numbers / nb_chunks;
}

void	move_to_top_next_number_from_chunk(t_stack **a, int end)
{
	int	hold_first;
	int	hold_second;
	int	i;

	hold_first = find_top_chunk(*a, end);
	hold_second = find_bottom_chunk(*a, end);
	i = -1;
	if (hold_first < hold_second)
	{
		while (++i < hold_first)
			rotate(a, 'a');
	}
	else
	{
		while (++i < hold_second)
			rrotate(a, 'a');
	}
}

void	push_number_to_stack_b(t_stack **a, t_stack **b, t_info *info)
{
	int	pos_min;

	pos_min = find_number(*b, find_min(*b));
	while (!is_current_greater_than_b(*a, *b) && pos_min > 0)
	{
		if (pos_min <= (info->size_b / 2))
			rotate(b, 'b');
		else
			rrotate(b, 'b');
		pos_min = find_number(*b, find_min(*b));
	}
	push('b', b, a, info);
}

void	move_max_number_to_stack_a(t_stack **a, t_stack **b, t_info *info)
{
	int	pos_max;

	pos_max = find_number(*b, find_max(*b));
	while (pos_max > 0)
	{
		if (info->size_b <= 1)
		{
			push('a', a, b, info);
			return ;
		}
		if (pos_max <= (info->size_b / 2))
			rotate(b, 'b');
		else
			rrotate(b, 'b');
		pos_max = find_number(*b, find_max(*b));
	}
	push('a', a, b, info);
}

void	sort_chunks(t_stack **a, t_stack **b, t_info *info, int nb_chunks)
{
	int	size_stack;
	int	start_chunk;
	int	end_chunk;

	size_stack = info->size_a;
	start_chunk = 0;
	end_chunk = (size_stack / nb_chunks) - 1;
	while (info->size_a > 0)
	{
		if (numbers_in_chunk(*a, start_chunk, end_chunk) == 0)
			set_chunk_range(&start_chunk, &end_chunk, size_stack, nb_chunks);
		move_to_top_next_number_from_chunk(a, end_chunk);
		push_number_to_stack_b(a, b, info);
	}
	while (info->size_b > 0)
	{
		move_max_number_to_stack_a(a, b, info);
	}
}
