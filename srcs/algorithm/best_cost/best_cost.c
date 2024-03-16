/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 21:30:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*define_chunks(int stack_size, int nbr_chunks)
{
	t_chunk	*chunks;
	int		i;

	chunks = ft_calloc(nbr_chunks + 1, sizeof(t_chunk));
	i = 0;
	while (i < nbr_chunks)
	{
		chunks[i].lower_limit = i * (stack_size / nbr_chunks);
		chunks[i].upper_limit = (i + 1) * (stack_size / nbr_chunks) - 1;
		if (i == nbr_chunks - 1)
			chunks[i].upper_limit = stack_size - 1;
		i++;
	}
	return (chunks);
}

int	is_number_on_chunk(int number, t_chunk chunk)
{
	return (number >= chunk.lower_limit && number <= chunk.upper_limit);
}

int	ammount_of_numbers_in_chunk(t_stack *stack, t_chunk chunk)
{
	while (stack)
	{
		if (is_number_on_chunk(stack->index, chunk))
			return (1);
		stack = stack->next;
	}
	return (0);
}

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

// #define N_CHUNKS 3

// t_chunk *chunks;
// int		i;

// chunks = define_chunks(info->size_a, N_CHUNKS);
// i = 2;
// while (i-- > 0)
// free(chunks);