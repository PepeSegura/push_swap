/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 03:37:25 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    sort_5(t_stack **a, t_stack **b, t_info *info)
{
    while (*a && info->size_a > 3)
    {
        while (find_number(*a, find_min(*a)) != 0)
            rotate(a, 'a');
        push('b', b, a, info);
    }
    sort_3(a);
    while (*b)
        push('a', a, b, info);
}
