/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:42:54 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/17 00:45:16 by psegura-         ###   ########.fr       */
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
