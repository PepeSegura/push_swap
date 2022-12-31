/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:00:39 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/31 04:41:38 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_b)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_b == NULL || stack_b[0]->next == NULL)
		return ;
	ptr1 = stack_b[0]->next;
	ptr2 = ptr1->next;
	ptr1->next = stack_b[0];
	stack_b[0]->next = ptr2;
	stack_b[0] = ptr1;
	write(1, "sb\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_b == NULL || stack_b[0]->next == NULL)
		return ;
	ptr1 = stack_b[0]->next;
	ptr2 = stack_b[0];
	while (ptr2->next != NULL)
			ptr2 = ptr2->next;
	ptr2->next = stack_b[0];
	stack_b[0]->next = NULL;
	stack_b[0] = ptr1;
	write(1, "rb\n", 3);
}

void	rrotate_b(t_list **stack_b)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_b == NULL || stack_b[0]->next == NULL)
		return ;
	ptr2 = stack_b[0];
	while (ptr2->next != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	ptr1->next = NULL;
	ptr2->next = stack_b[0];
	stack_b[0] = ptr2;
	write(1, "rrb\n", 4);
}
