/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:09:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/03 17:43:12 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_algorithm(t_list **stack_a, t_list **stack_b, t_cosas *cosas)
{
	if (ft_is_ordered(stack_a[0]) == 1)
		return ;
	else if (cosas->number_count == 2 && ft_is_ordered(stack_a[0]) == 0)
		swap_a(stack_a);
	else if (cosas->number_count == 3)
		ft_sort_max_3(stack_a);
	else if (cosas->number_count <= 45)
		ft_sort_max_10(stack_a, stack_b, cosas);
	else
		ft_sort_max_500(stack_a, stack_b, cosas);
}

void	ft_sort_max_3(t_list **stack_a)
{
	if ((int)stack_a[0]->next->content == find_min(stack_a[0])
		&& (int)ft_lstlast(stack_a[0])->content == find_max(stack_a[0]))
		swap_a(stack_a);
	if ((int)stack_a[0]->content == find_max(stack_a[0])
		&& (int)ft_lstlast(stack_a[0])->content == find_min(stack_a[0]))
	{
		swap_a(stack_a);
		rrotate_a(stack_a);
	}
	if ((int)stack_a[0]->content == find_max(stack_a[0])
		&& (int)stack_a[0]->next->content == find_min(stack_a[0]))
		rotate_a(stack_a);
	if ((int)stack_a[0]->content == find_min(stack_a[0])
		&& (int)stack_a[0]->next->content == find_max(stack_a[0]))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	if ((int)stack_a[0]->next->content == find_max(stack_a[0])
		&& (int)ft_lstlast(stack_a[0])->content == find_min(stack_a[0]))
		rrotate_a(stack_a);
}

void	ft_sort_max_10(t_list **stack_a, t_list **stack_b, t_cosas *cosas)
{
	cosas->stack_a_size = cosas->number_count;
	while (stack_a[0] && cosas->stack_a_size > 3)
	{
		while (find_num(stack_a[0], find_min(stack_a[0])) != 0)
		{
			if (find_num(stack_a[0], find_min(stack_a[0]))
				<= (ft_lstsize(stack_a[0]) / 2))
				rotate_a(stack_a);
			else
				rrotate_a(stack_a);
		}
		if (ft_is_ordered(stack_a[0]) == 1)
			break ;
		if (find_num(stack_a[0], find_min(stack_a[0])) == 0)
			push_b(stack_a, stack_b, cosas);
	}
	ft_sort_max_3(stack_a);
	while (stack_b[0])
		push_a(stack_a, stack_b, cosas);
}

void	ft_sort_max_500(t_list **stack_a, t_list **stack_b, t_cosas *c)
{
	int	tmp;
	int	size;
	int	nbr_bites;

	c->i = -1;
	nbr_bites = ft_max_bites(stack_a[0]);
	size = ft_lstsize(stack_a[0]);
	while (++c->i < nbr_bites)
	{
		c->j = -1;
		while (++c->j < size)
		{
			tmp = (int)stack_a[0]->content;
			if ((tmp >> c->i & 1) == 1)
				rotate_a(stack_a);
			else if (ft_is_ordered(stack_a[0]) == 1)
				break ;
			else
				push_b(stack_a, stack_b, c);
		}
		while (ft_lstsize(stack_b[0]) != 0)
			push_a(stack_a, stack_b, c);
	}
}
