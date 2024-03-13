/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:01:17 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/13 23:05:43 by psegura-         ###   ########.fr       */
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

#define PRINT "Content: [%d]\t Idx: [%d]\t Pos: [%d]\t Target: [%d]\t Dist_A: [%d]\t Dist_B: [%d]\n"

void	print_data(t_stack node)
{
	ft_dprintf(2, PRINT, node.content, node.index, node.pos, node.target, node.dist_a, node.dist_b);	
}

void	stack_iteri(t_stack *stack, void(*f)(t_stack))
{
	ft_dprintf(2, "Stack: \n");
	while (stack)
	{
		f(*stack);
		stack = stack->next;
	}
	ft_dprintf(2, "\n");
}
