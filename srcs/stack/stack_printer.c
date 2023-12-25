/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:01:17 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 02:13:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_content(t_stack *stack)
{
	ft_dprintf(2, "Stack: \n");
	while (stack)
	{
		ft_dprintf(2, "%d ", stack->content);
		stack = stack->next;
	}
	ft_dprintf(2, "\n");
}

void	print_stack_index(t_stack *stack)
{
	ft_dprintf(2, "Stack: \n");
	while (stack)
	{
		ft_dprintf(2, "%d ", stack->index);
		stack = stack->next;
	}
	ft_dprintf(2, "\n");
}