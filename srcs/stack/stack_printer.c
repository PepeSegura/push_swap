/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:01:17 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 21:38:14 by psegura-         ###   ########.fr       */
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

#define PRINT_AB "Content: [%d]\t Idx: [%d]\t Pos: \
[%d]\t Target: [%d]\t Dist_A: [%d]\t Dist_B: [%d]\n"
#define PRINT_BA "Content: [%d]\t Idx: [%d]\t Pos: \
[%d]\t Target: [%d]\t Dist_B: [%d]\t Dist_A: [%d]\n"

void	print_ab(t_stack node)
{
	ft_dprintf(2, PRINT_AB, node.content, node.index, node.pos,
		node.target, node.dist_a, node.dist_b);
}

void	print_ba(t_stack node)
{
	ft_dprintf(2, PRINT_BA, node.content, node.index, node.pos,
		node.target, node.dist_b, node.dist_a);
}

void	stack_iteri(t_stack *stack, void (*f)(t_stack))
{
	ft_dprintf(2, "Stack: \n");
	while (stack)
	{
		f(*stack);
		stack = stack->next;
	}
	ft_dprintf(2, "\n");
}
