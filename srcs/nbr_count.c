/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:05:09 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/30 15:00:42 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_already_checked(int number, long *numbers, int i)
{
	i--;
	while (i >= 0)
	{
		if (numbers[i] == number)
			return (1);
		i--;
	}
	return (0);
}

void	ft_check_repeat(long *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] < INT_MIN || numbers[i] > INT_MAX)
			ft_print_error("Number out of range\n");
		if (ft_already_checked(numbers[i], numbers, i) == 1)
			ft_print_error("There are numbers repeated\n");
		i++;
	}
}
