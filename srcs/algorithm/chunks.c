/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/27 00:26:47 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_chunk_range(int *start, int *end, int numbers, int nb_chunks)
{
    if (*end + 1 >= numbers)
        return ;
    *start += numbers / nb_chunks;
    *end += numbers / nb_chunks;
}

int isCurrentGreaterThanB(t_stack *a, t_stack *b)
{
    int current = a->index;
    
    while (b != NULL)
    {
        if (current > b->index)
            return (1);

        b = b->next;
    }

    return (0);
}

int isCurrentSmallerThanA(t_stack *b, t_stack *a)
{
    int current = b->content;

    while (a != NULL)
    {
        if (current < a->content)
            return (1);

        a = a->next;
    }
    return (0);
}

void	sort_chunks(t_stack **a, t_stack **b, t_info *info, int nb_chunks)
{
	int	numbers;
	int	start;
	int	end;
	int	i;
	int	hold_first;
	int	hold_second;

	numbers = info->size_a;
	start = 0;
	end = (numbers / nb_chunks) - 1;
	while (info->size_a > 0)
	{
        if (numbers_in_chunk(*a, start, end) == 0)
            set_chunk_range(&start, &end, numbers, nb_chunks);
		i = -1;
		hold_first = find_top_chunk(*a, end);
		hold_second = find_bottom_chunk(*a, end);
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
        int pos_min = -1;
        pos_min = find_number(*b, find_min(*b));
		while (!isCurrentGreaterThanB(*a, *b) && pos_min > 0)
		{
			if (pos_min <= (info->size_b / 2))
				rotate(b, 'b');
			else
				rrotate(b, 'b');
            pos_min = find_number(*b, find_min(*b));
		}
		push('b', b, a, info);
	}
	while (info->size_b > 0)
    {
        int pos_max = -1;

        pos_max = find_number(*b, find_max(*b));

        // if (!isCurrentSmallerThanA(*b, *a) && pos_max > 0)
        // {
            while (pos_max > 0)
            {
                if (info->size_b <= 1)
                {
                    push('a', a, b, info);
                    return ;
                }
                if (pos_max <= (info->size_b / 2))
                    rotate(b, 'b');
                else
                    rrotate(b, 'b');
                pos_max = find_number(*b, find_max(*b));
            }
        // }
		push('a', a, b, info);
    }
}
