/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:01:21 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/31 04:45:53 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if ((*stack_a == NULL || stack_a[0]->next == NULL)
		|| (*stack_b == NULL || stack_b[0]->next == NULL))
		return ;
	ptr1 = stack_a[0]->next;
	ptr2 = ptr1->next;
	ptr1->next = stack_a[0];
	stack_a[0]->next = ptr2;
	stack_a[0] = ptr1;
	ptr1 = stack_b[0]->next;
	ptr2 = ptr1->next;
	ptr1->next = stack_b[0];
	stack_b[0]->next = ptr2;
	stack_b[0] = ptr1;
	write(1, "ss\n", 3);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if ((*stack_a == NULL || stack_a[0]->next == NULL)
		|| (*stack_b == NULL || stack_b[0]->next == NULL))
		return ;
	ptr1 = stack_a[0]->next;
	ptr2 = stack_a[0];
	while (ptr2->next != NULL)
		ptr2 = ptr2->next;
	ptr2->next = stack_a[0];
	stack_a[0]->next = NULL;
	stack_a[0] = ptr1;
	ptr1 = stack_b[0]->next;
	ptr2 = stack_b[0];
	while (ptr2->next != NULL)
		ptr2 = ptr2->next;
	ptr2->next = stack_b[0];
	stack_b[0]->next = NULL;
	stack_b[0] = ptr1;
	write(1, "rr\n", 3);
}

void	rrotate_ab(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if ((*stack_a == NULL || stack_a[0]->next == NULL)
		|| (*stack_b == NULL || stack_b[0]->next == NULL))
		return ;
	ptr2 = stack_a[0];
	while (ptr2->next != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	ptr1->next = NULL;
	ptr2->next = stack_a[0];
	stack_a[0] = ptr2;
	ptr2 = stack_b[0];
	while (ptr2->next != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	ptr1->next = NULL;
	ptr2->next = stack_b[0];
	stack_b[0] = ptr2;
	write(1, "rrr\n", 4);
}
