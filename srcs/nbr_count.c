/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:05:09 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/06 13:34:07 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_already_checked(int number, long *numbers, int i)
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
			ft_print_error("Number out of range.\n");
		if (ft_already_checked(numbers[i], numbers, i) == 1)
			ft_print_error("There are numbers repeated.\n");
		i++;
	}
}
