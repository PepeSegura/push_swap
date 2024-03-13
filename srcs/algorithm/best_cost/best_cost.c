/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/13 19:37:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_chunk
{
	int lower_limit;
	int upper_limit;
}	t_chunk;

t_chunk *define_chunks(int stack_size, int nbr_chunks)
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
	// ft_dprintf(2, "stack_size: %d  number of chunks: %d size_chunks: %d\n", stack_size, nbr_chunks, stack_size / nbr_chunks);
	// for (int i = 0; i < nbr_chunks; i++)
	// {
	// 	ft_dprintf(2, "Chunk %d: [%d - %d]\n", i, chunks[i].lower_limit, chunks[i].upper_limit);	
	// 	ft_dprintf(2, "---------------------\n");
	// }
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

#define N_CHUNKS 11

void	best_cost(t_stack **a, t_stack **b, t_info *info)
{
	t_chunk *chunks;
	int		i;

	chunks = define_chunks(info->size_a, N_CHUNKS);
	i = 0;
	while (info->size_a > 0)
	{
		if (ammount_of_numbers_in_chunk(*a, chunks[i]) == 0 && i < N_CHUNKS)
			i++;
		move_to_top_next_number_from_chunk(a, chunks[i].upper_limit);
		push_number_to_stack_b(a, b, info);
	}
	sort_3(a);
	while (info->size_b > 0)
	{
		move_max_number_to_stack_a(a, b, info);
	}
	free(chunks);
}
