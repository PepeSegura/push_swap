/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/24 20:26:29 by psegura-         ###   ########.fr       */
=======
/*   Updated: 2024/03/04 04:03:00 by psegura-         ###   ########.fr       */
>>>>>>> 14c3b698679dba075c0d91a400b95260e0d09489
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, t_info *info)
{
	if (is_ordered(*a))
		return ;
	else if (info->size_a == 2 && !is_ordered(*a))
		swap(a, 'a');
	else if (info->size_a == 3)
		sort_3(a);
	else if (info->size_a < 10)
		sort_5(a, b, info);
	else if (info->size_a <= 100)
		sort_chunks(a, b, info, 5);
	else
		radix(a, b, info);
<<<<<<< HEAD
	exit (EXIT_SUCCESS);
=======
		// best_cost(a, b, info);
>>>>>>> 14c3b698679dba075c0d91a400b95260e0d09489
}
