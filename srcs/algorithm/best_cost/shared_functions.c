/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:27:33 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 21:27:43 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_until_0_distance(t_stack **stack, int distance, int c)
{
	if (distance > 0)
	{
		while (distance > 0)
		{
			rotate(stack, c);
			distance--;
		}
	}
	else if (distance < 0)
	{
		while (distance < 0)
		{
			rrotate(stack, c);
			distance++;
		}
	}
}

int	calc_moves_same_dir(int dist_a, int dist_b)
{
	const int	abs_a = abs(dist_a);
	const int	abs_b = abs(dist_b);
	int			max;

	max = abs_a;
	if (abs_a < abs_b)
		max = abs_b;
	return (max);
}

int	calc_moves_oposite_dir(int dist_a, int dist_b)
{
	return (abs(dist_a) + abs(dist_b));
}

void	set_pos(t_stack *a, t_stack *b)
{
	int	pos;

	pos = 0;
	while (a)
	{
		a->pos = pos;
		pos++;
		a = a->next;
	}
	pos = 0;
	while (b)
	{
		b->pos = pos;
		pos++;
		b = b->next;
	}
}
