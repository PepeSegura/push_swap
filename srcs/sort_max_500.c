/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:35:17 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/01 20:37:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_max_500(t_list *stack_a, t_list *stack_b, t_cosas *cosas)
{
	cosas->stack_a_size = cosas->number_count;
	while (stack_a && cosas->stack_a_size > 3)
	{
		while (find_num(stack_a, find_min(stack_a)) != 0)
		{
			if (find_num(stack_a, find_min(stack_a))
				<= (ft_lstsize(stack_a) / 2))
				rotate_a(&stack_a);
			else
				rrotate_a(&stack_a);
		}
		if (ft_is_ordered(stack_a) == 1)
			break ;
		if (find_num(stack_a, find_min(stack_a)) == 0)
			push_b(&stack_a, &stack_b, cosas);
	}
	ft_sort_max_3(stack_a);
	while (stack_b)
		push_a(&stack_a, &stack_b, cosas);
}