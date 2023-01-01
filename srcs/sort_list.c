/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:09:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/01 20:34:54 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_algorithm(t_list *stack_a, t_list *stack_b, t_cosas *cosas)
{
	if (ft_is_ordered(stack_a) == 1)
		return ;
	else if (cosas->number_count == 2 && ft_is_ordered(stack_a) == 0)
		swap_a(&stack_a);
	else if (cosas->number_count <= 10)
		ft_sort_max_10(stack_a, stack_b, cosas);
	else
		ft_sort_max_500(stack_a, stack_b, cosas);
}

void	ft_sort_max_3(t_list *stack_a)
{
	if ((int)stack_a->next->content == find_min(stack_a)
		&& (int)ft_lstlast(stack_a)->content == find_max(stack_a))
		swap_a(&stack_a);
	if ((int)stack_a->content == find_max(stack_a)
		&& (int)ft_lstlast(stack_a)->content == find_min(stack_a))
	{
		swap_a(&stack_a);
		rrotate_a(&stack_a);
	}
	if ((int)stack_a->content == find_max(stack_a)
		&& (int)stack_a->next->content == find_min(stack_a))
		rotate_a(&stack_a);
	if ((int)stack_a->content == find_min(stack_a)
		&& (int)stack_a->next->content == find_max(stack_a))
	{
		swap_a(&stack_a);
		rotate_a(&stack_a);
	}
	if ((int)stack_a->next->content == find_max(stack_a)
		&& (int)ft_lstlast(stack_a)->content == find_min(stack_a))
		rrotate_a(&stack_a);
}

void	ft_sort_max_10(t_list *stack_a, t_list *stack_b, t_cosas *cosas)
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
