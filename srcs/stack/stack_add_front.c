/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:18:45 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 02:10:26 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
    if (!new)
        return;
    new->next = *stack;
    new->prev = NULL;
    if (*stack)
        (*stack)->prev = new;
    *stack = new;
}
