/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:53:55 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/31 04:42:56 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_a == NULL || stack_a[0]->next == NULL)
		return ;
	ptr1 = stack_a[0]->next;
	ptr2 = ptr1->next;
	ptr1->next = stack_a[0];
	stack_a[0]->next = ptr2;
	stack_a[0] = ptr1;
	write(1, "sa\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_a == NULL || stack_a[0]->next == NULL)
		return ;
	ptr1 = stack_a[0]->next;
	ptr2 = stack_a[0];
	while (ptr2->next != NULL)
			ptr2 = ptr2->next;
	ptr2->next = stack_a[0];
	stack_a[0]->next = NULL;
	stack_a[0] = ptr1;
	write(1, "ra\n", 3);
}

void	rrotate_a(t_list **stack_a)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_a == NULL || stack_a[0]->next == NULL)
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
	write(1, "rra\n", 4);
}
