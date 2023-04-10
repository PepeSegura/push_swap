/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:53:55 by psegura-          #+#    #+#             */
/*   Updated: 2023/04/10 17:32:20 by psegura-         ###   ########.fr       */
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

void	push_a(t_list **stack_a, t_list **stack_b, t_cosas *cosas)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	cosas->stack_a_size++;
	cosas->stack_b_size--;
	write(1, "pa\n", 3);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*new_head;
	t_list	*aux;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	new_head = (*stack_a)->next;
	aux = (*stack_a);
	while (aux->next != NULL)
			aux = aux->next;
	aux->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a) = new_head;
	write(1, "ra\n", 3);
}

void	rrotate_a(t_list **stack_a)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ptr2 = (*stack_a);
	while (ptr2->next != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	ptr1->next = NULL;
	ptr2->next = (*stack_a);
	(*stack_a) = ptr2;
	write(1, "rra\n", 4);
}
