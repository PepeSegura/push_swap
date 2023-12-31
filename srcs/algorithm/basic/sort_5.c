/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/26 23:48:00 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **a, t_stack **b, t_info *info)
{
	while (*a && info->size_a > 3)
	{
		while (find_number(*a, find_min(*a)) != 0)
		{
			if (find_number(*a, find_min(*a)) <= (info->size_a / 2))
				rotate(a, 'a');
			else
				rrotate(a, 'a');
		}
		if (is_ordered(*a))
			break ;
		push('b', b, a, info);
	}
	sort_3(a);
	while (*b)
		push('a', a, b, info);
}
