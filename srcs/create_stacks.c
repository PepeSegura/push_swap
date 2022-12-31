/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:50:34 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/31 00:31:39 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_stacks(long *numbers, t_cosas *c, t_list *stack_a)
{
	long	i;

	i = 0;
	while (i < c->number_count)
	{
		ft_lstadd_back(&stack_a, ft_lstnew((void *)numbers[i]));
		i++;
	}
	return (stack_a);
}
