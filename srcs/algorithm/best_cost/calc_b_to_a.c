/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:38:06 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 21:23:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_move(t_stack **a, t_stack **b, t_info *info, int dist[2])
{
	if (dist[A] > 0 && dist[B] > 0)
	{
		while (dist[A] > 0 && dist[B] > 0)
		{
			dist[A]--;
			dist[B]--;
			double_rotate(a, b);
		}
	}
	else if (dist[A] < 0 && dist[B] < 0)
	{
		while (dist[A] < 0 && dist[B] < 0)
		{
			dist[A]++;
			dist[B]++;
			double_rrotate(a, b);
		}
	}
	rotate_until_0_distance(a, dist[A], 'a');
	rotate_until_0_distance(b, dist[B], 'b');
	if (*b)
		push('a', a, b, info);
}

static void	locate_cheapest_b_to_a(t_stack **a, t_stack **b, t_info *info)
{
	const t_stack	*stack_aux = *b;
	int				cheapest;
	int				aux;
	int				dist[2];

	aux = 0;
	cheapest = info->size_a + info->size_b;
	while (stack_aux)
	{
		if ((stack_aux->dist_a >= 0 && stack_aux->dist_b >= 0)
			|| (stack_aux->dist_a < 0 && stack_aux->dist_b < 0))
			aux = calc_moves_same_dir(stack_aux->dist_a, stack_aux->dist_b);
		else if ((stack_aux->dist_a < 0 && stack_aux->dist_b >= 0)
			|| (stack_aux->dist_a >= 0 && stack_aux->dist_b < 0))
			aux = calc_moves_oposite_dir(stack_aux->dist_a, stack_aux->dist_b);
		if (aux < cheapest)
		{
			cheapest = aux;
			dist[A] = stack_aux->dist_a;
			dist[B] = stack_aux->dist_b;
		}
		stack_aux = stack_aux->next;
	}
	exec_move(a, b, info, dist);
}

void	move_cheapest_b_to_a(t_stack **b, t_stack **a, t_info *info)
{
	set_target_and_dist_b(a, b, info);
	locate_cheapest_b_to_a(a, b, info);
}
