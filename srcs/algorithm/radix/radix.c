/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:31:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/31 19:31:20 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bites(t_stack *stack)
{
	int	nbr_bites;
	int	max;

	max = stack_size(stack) - 1;
	nbr_bites = 0;
	while ((max >> nbr_bites) != 0)
		nbr_bites++;
	return (nbr_bites);
}

void	radix(t_stack **a, t_stack **b, t_info *info)
{
	int	tmp;
	int	size;
	int	nbr_bites;
	int	i;
	int	j;

	i = -1;
	nbr_bites = max_bites(*a);
	size = stack_size(*a);
	while (++i < nbr_bites)
	{
		j = -1;
		while (++j < size)
		{
			tmp = (*a)->index;
			if ((tmp >> i & 1) == 1)
				rotate(a, 'a');
			else if (is_ordered(*a))
				break ;
			else
				push('b', b, a, info);
		}
		while (info->size_b != 0)
			push('a', a, b, info);
	}
}
