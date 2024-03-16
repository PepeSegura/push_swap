/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_and_dist_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:27:57 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 21:27:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_stack *b, int index_a, int tmp_index, int tmp_pos)
{
	const t_stack	*aux = b;

	while (b)
	{
		if (index_a > b->index && tmp_index < b->index)
		{
			tmp_index = b->index;
			tmp_pos = b->pos;
		}
		b = b->next;
	}
	if (tmp_index > INT_MIN)
		return (tmp_pos);
	while (aux)
	{
		if (tmp_index < aux->index)
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
	while (a)
	{
		tmp_pos = get_target(b, a->index, INT_MIN, tmp_pos);
		a->target = tmp_pos;
		a = a->next;
	}
}

static void	set_dist_a(t_stack *stack, t_info *info)
{
	while (stack)
	{
		stack->dist_a = stack->pos;
		if (stack->pos > info->size_a / 2)
			stack->dist_a = (info->size_a - stack->pos) * -1;
		stack = stack->next;
	}
}

static void	set_dist_b(t_stack *stack, t_info *info)
{
	while (stack)
	{
		stack->dist_b = stack->target;
		if (stack->target > info->size_b / 2)
			stack->dist_b = (info->size_b - stack->target) * -1;
		stack = stack->next;
	}
}

void	set_target_and_dist_a(t_stack **a, t_stack **b, t_info *info)
{
	set_pos(*a, *b);
	set_target(*a, *b);
	set_dist_a(*a, info);
	set_dist_b(*a, info);
}
