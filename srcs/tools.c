/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:13:06 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/03 15:44:23 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ordered(t_list *stack_a)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (stack_a->next == NULL)
		return (1);
	ptr1 = stack_a;
	ptr2 = stack_a->next;
	while (ptr2 != NULL)
	{
		if ((int)ptr1->content > (int)ptr2->content)
			return (0);
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}
	return (1);
}

int	find_min(t_list *stack)
{
	t_list	*ptr1;
	int		min;

	if (stack->next == NULL)
		return ((int)stack->content);
	ptr1 = stack;
	min = (int)ptr1->content;
	while (ptr1->next != NULL)
	{
		if ((int)ptr1->next->content < min)
			min = (int)ptr1->next->content;
		ptr1 = ptr1->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	t_list	*ptr1;
	int		max;

	if (stack->next == NULL)
		return (1);
	ptr1 = stack;
	max = (int)ptr1->content;
	while (ptr1->next != NULL)
	{
		if ((int)ptr1->next->content > max)
			max = (int)ptr1->next->content;
		ptr1 = ptr1->next;
	}
	return (max);
}

int	find_num(t_list *stack, int num)
{
	t_list	*ptr1;
	int		count;

	count = 0;
	ptr1 = stack;
	while (ptr1->next != NULL)
	{
		if ((int)ptr1->content == num)
			return (count);
		ptr1 = ptr1->next;
		count++;
	}
	return (count);
}

int	ft_max_bites(t_list *list)
{
	int	nbr_bites;
	int	max;

	max = ft_lstsize(list) - 1;
	nbr_bites = 0;
	while ((max >> nbr_bites) != 0)
		nbr_bites++;
	return (nbr_bites);
}
