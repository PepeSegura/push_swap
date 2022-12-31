/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:09:46 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/31 19:19:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_algorithm(t_list *stack_a, t_list *stack_b, t_cosas *cosas)
{
	if (ft_is_ordered(stack_a) == 1)
		return ;
	else if (cosas->number_count == 2 && ft_is_ordered(stack_a) == 0)
		swap_a(&stack_a);
	else if (cosas->number_count <= 3)
		ft_sort_max_3(stack_a);
	else if (cosas->number_count <= 5)
		ft_sort_max_5(stack_a, stack_b, cosas);
	else
		ft_sort_max_100(stack_a, stack_b, cosas);
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

void	ft_sort_max_5(t_list *stack_a, t_list *stack_b, t_cosas *cosas)
{
	if (cosas->number_count > 0)
		cosas->number_count = cosas->number_count;
	while (stack_a)
	{
		while (find_num(stack_a, find_min(stack_a)) != 0)
		{
			if (find_num(stack_a, find_min(stack_a))
				<= (ft_lstsize(stack_a) / 2))
				rotate_a(&stack_a);
			else
				rrotate_a(&stack_a);
		}
		if (find_num(stack_a, find_min(stack_a)) == 0)
			push_b(&stack_a, &stack_b);
	}
	while (stack_b)
	{
		push_a(&stack_a, &stack_b);
	}
}

void	ft_sort_max_100(t_list *stack_a, t_list *stack_b, t_cosas *cosas)
{
	if (cosas->number_count > 0)
		cosas->number_count = cosas->number_count;
	while (stack_a)
	{
		while (find_num(stack_a, find_min(stack_a)) != 0)
		{
			if (find_num(stack_a, find_min(stack_a))
				<= (ft_lstsize(stack_a) / 2))
				rotate_a(&stack_a);
			else
				rrotate_a(&stack_a);
		}
		if (find_num(stack_a, find_min(stack_a)) == 0)
			push_b(&stack_a, &stack_b);
	}
	while (stack_b)
	{
		push_a(&stack_a, &stack_b);
	}
}
