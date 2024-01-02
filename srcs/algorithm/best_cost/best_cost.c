/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/02 16:44:28 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_cost(t_stack **a, t_stack **b, t_info *info)
{
	int	size_stack;

	size_stack = info->size_a;
	while (info->size_a > 3)
	{
		while (info->size_a > size_stack / 2)
		{
			if ((*a)->index > size_stack / 2)
				rotate(a, 'a');
			else
				push('b', b, a, info);
		}
		push('b', b, a, info);
	}
	sort_3(a);
	while (info->size_b > 0)
	{
		move_max_number_to_stack_a(a, b, info);
	}
}
