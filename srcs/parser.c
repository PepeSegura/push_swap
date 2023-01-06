/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:51:30 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/06 13:34:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_nbr_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || ft_isdigit(str[i]) == 1
				|| ((str[i] == '-' || str[i] == '+')
					&& ft_isdigit(str[i + 1]) == 1 && str[i - 1] == ' ')))
			i++;
		else if ((i == 0 && (str[i] == '-' || str[i] == '+'))
			&& ft_isdigit(str[i + 1]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_parser(t_arguments *args)
{
	int		i;

	i = 1;
	while (i < args->argc)
	{
		if (ft_is_nbr_space(args->argv[i]) == 0)
			return (0);
		i++;
	}		
	return (1);
}

int	ft_nbr_count(t_arguments *args)
{
	char	**numbers;
	int		nbr_count;
	int		i;

	i = 1;
	numbers = NULL;
	nbr_count = 0;
	while (i < args->argc)
	{
		numbers = ft_split(args->argv[i], ' ');
		nbr_count = nbr_count + ft_matrix_len(numbers);
		ft_free_matrix(numbers);
		i++;
	}
	return (nbr_count);
}

long	*ft_store_numbers(t_cosas *c)
{
	long	*numbers;

	c->k = 1;
	c->number_count = ft_nbr_count(&c->args);
	numbers = (long *)malloc(sizeof(long) * c->number_count);
	if (!numbers)
		ft_print_error("Malloc KO.\n");
	while (c->i < c->number_count)
	{
		c->matrix = ft_split(c->args.argv[c->k], ' ');
		if (c->matrix == NULL)
			ft_print_error("Malloc KO.\n");
		c->j = 0;
		while (c->matrix && c->matrix[c->j] != NULL)
		{
			if (ft_strlen(c->matrix[c->j]) <= 12)
				numbers[c->i++] = ft_atoi_long(c->matrix[c->j++]);
			else
				ft_print_error("Number out of range.\n");
		}
		ft_free_matrix(c->matrix);
		c->k++;
	}
	return (numbers);
}
