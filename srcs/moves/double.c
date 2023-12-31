/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:03:14 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/31 19:30:56 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack **a, t_stack **b)
{
	t_stack	*second_a;
	t_stack	*second_b;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	second_a = (*a)->next;
	(*a)->next = second_a->next;
	second_a->next = *a;
	second_a->prev = NULL;
	if ((*a)->next)
		(*a)->next->prev = *a;
	(*a)->prev = second_a;
	*a = second_a;
	second_b = (*b)->next;
	(*b)->next = second_b->next;
	second_b->next = *b;
	second_b->prev = NULL;
	if ((*b)->next)
		(*b)->next->prev = *b;
	(*b)->prev = second_b;
	*b = second_b;
	write_move("s", 's');
}

void	double_rotate(t_stack **a, t_stack **b)
{
	t_stack	*new_head_a;
	t_stack	*last_a;
	t_stack	*new_head_b;
	t_stack	*last_b;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	new_head_a = (*a)->next;
	last_a = stack_last(*a);
	last_a->next = *a;
	(*a)->next = NULL;
	(*a)->prev = last_a;
	*a = new_head_a;
	if (new_head_a)
		new_head_a->prev = NULL;
	new_head_b = (*b)->next;
	last_b = stack_last(*b);
	last_b->next = *b;
	(*b)->next = NULL;
	(*b)->prev = last_b;
	*b = new_head_b;
	if (new_head_b)
		new_head_b->prev = NULL;
	write_move("r", 'r');
}

void	double_rrotate(t_stack **a, t_stack **b)
{
	t_stack	*last_a;
	t_stack	*last_b;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last_a = stack_last(*a);
	last_a->prev->next = NULL;
	last_a->next = *a;
	last_a->prev = NULL;
	(*a)->prev = last_a;
	*a = last_a;
	last_b = stack_last(*b);
	last_b->prev->next = NULL;
	last_b->next = *b;
	last_b->prev = NULL;
	(*b)->prev = last_b;
	*b = last_b;
	write_move("rr", 'r');
}
