/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/17 00:29:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, t_info *info)
{
	if (is_ordered(*a))
		return ;
	else if (info->size_a == 2 && !is_ordered(*a))
		swap(a, 'a');
	else if (info->size_a == 3)
		sort_3(a);
	else if (info->size_a < 10)
		sort_5(a, b, info);
	else if (info->size_a <= 100)
		best_cost(a, b, info);
	else
		turk_chunks(a, b, info, info->size_a / 7);
}
