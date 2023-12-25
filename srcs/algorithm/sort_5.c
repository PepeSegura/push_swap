/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 02:17:23 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 05:07:21 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    sort_5(t_stack **a, t_stack **b, t_info *info)
{
    while (*a && info->size_a > 3)
    {
        while (find_number(*a, find_min(*a)) != 0)
        {
        	if (find_number(*a, find_min(*a)) <= (info->size_a / 2))
				rotate(a, 'a');
			else
				rrotate(a, 'a');
        }
        if (is_ordered(*a))
			break ;
        push('b', b, a, info);
    }
    sort_3(a);
    while (*b)
        push('a', a, b, info);
}

void    sort_chunks(t_stack **a, t_stack **b, t_info *info)
{
    (void)b, (void)info;

    while (info->size_a > 0)
    {
        int i = -1;
        int hold_first = find_top_chunk(*a, info->size_a);
        int hold_second = find_bottom_chunk(*a, info->size_a);

        // printf("Cost hold_first: %d hold_second: %d\n", hold_first, hold_second);
        if (hold_first < hold_second)
        {
            while (++i < hold_first)
                rotate(a, 'a');
        }
        else
        {
            while (++i < hold_second)
                rrotate(a, 'a');
        }
        while (find_number(*b, find_min(*b)) != 0)
		{
			if (find_number(*b, find_min(*b) <= (info->size_b / 2)))
				rotate(b, 'b');
			else
				rrotate(b, 'b');
		}
        push('b', b, a, info);
    }
    while (info->size_b > 0)
        push('a', a, b, info);
}