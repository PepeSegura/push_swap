/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_and_dist_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:22:55 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 21:23:43 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_stack *a, int index_b, int tmp_index, int tmp_pos)
{
	const t_stack	*aux = a;

	while (a)
	{
		if (index_b < a->index && tmp_index > a->index)
		{
			tmp_index = a->index;
			tmp_pos = a->pos;
		}
		a = a->next;
	}
	if (tmp_index < INT_MAX)
		return (tmp_pos);
	while (aux)
	{
		if (tmp_index > aux->index)
		{
			tmp_index = aux->index;
			tmp_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (tmp_pos);
}

static void	set_target(t_stack *a, t_stack *b)
{
	int	tmp_pos;

	tmp_pos = 0;
	while (b)
	{
		tmp_pos = get_target(a, b->index, INT_MAX, tmp_pos);
		b->target = tmp_pos;
		b = b->next;
	}
}

static void	set_dist_a(t_stack *stack, t_info *info)
{
	while (stack)
	{
		stack->dist_a = stack->target;
		if (stack->target > info->size_a / 2)
			stack->dist_a = (info->size_a - stack->target) * -1;
		stack = stack->next;
	}
}

static void	set_dist_b(t_stack *stack, t_info *info)
{
	while (stack)
	{
		stack->dist_b = stack->pos;
		if (stack->pos > info->size_b / 2)
			stack->dist_b = (info->size_b - stack->pos) * -1;
		stack = stack->next;
	}
}

void	set_target_and_dist_b(t_stack **a, t_stack **b, t_info *info)
{
	set_pos(*a, *b);
	set_target(*a, *b);
	set_dist_a(*b, info);
	set_dist_b(*b, info);
}
