/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:05:09 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/29 22:24:27 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_already_checked(int number, int *numbers, int i)
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

void	ft_check_repeat(int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_already_checked(numbers[i], numbers, i) == 1)
			ft_print_error("There are numbers repeated\n");
		i++;
	}
}
