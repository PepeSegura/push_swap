/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:42:24 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/02 20:40:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(long *tab, int size)
{
	int		i;
	long	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_reorder_tab(long *tab, long *numbers, long *result, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] == numbers[j])
				result[j] = i;
			j++;
		}
	}
}

void	ft_copy_tab(long *tab, long *numbers, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		tab[i] = numbers[i];
}

void	ft_sort_tab(long *numbers, int size)
{
	long	*tab;
	long	*result;

	tab = (long *)malloc(sizeof(long) * size);
	result = (long *)malloc(sizeof(long) * size);
	if (!tab || !result)
		ft_putstr_fd("Malloc KO", 2);
	ft_copy_tab(tab, numbers, size);
	ft_bubble_sort(tab, size);
	ft_reorder_tab(tab, numbers, result, size);
	ft_copy_tab(numbers, result, size);
	free(tab);
	free(result);
}
