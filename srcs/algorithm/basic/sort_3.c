/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/04 03:34:51 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	if ((*stack)->next->index == find_max(*stack)
		&& stack_last(*stack)->index == find_min(*stack))
		rrotate(stack, 'a');
	if ((*stack)->next->index == find_min(*stack)
		&& stack_last(*stack)->index == find_max(*stack))
		swap(stack, 'a');
	if ((*stack)->index == find_max(*stack)
		&& stack_last(*stack)->index == find_min(*stack))
	{
		swap(stack, 'a');
		rrotate(stack, 'a');
	}
	if ((*stack)->index == find_max(*stack)
		&& (*stack)->next->index == find_min(*stack))
		rotate(stack, 'a');
	if ((*stack)->index == find_min(*stack)
		&& (*stack)->next->index == find_max(*stack))
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}
