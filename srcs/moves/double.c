/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:03:14 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/01 00:07:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack **a, t_stack **b)
{
	swap(a, 'c');
	swap(b, 'c');
	write_move("s", 's');
}

void	double_rotate(t_stack **a, t_stack **b)
{
	rotate(a, 'c');
	rotate(b, 'c');
	write_move("r", 'r');
}

void	double_rrotate(t_stack **a, t_stack **b)
{
	rrotate(a, 'c');
	rrotate(b, 'c');
	write_move("rr", 'r');
}
