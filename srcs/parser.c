/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:51:30 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/29 22:04:53 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_nbr_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || ft_isdigit(str[i]) == 1
				|| ((str[i] == '-' || str[i] == '+')
					&& ft_isdigit(str[i + 1]) == 1)))
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

int	*ft_store_numbers(t_arguments *args, t_cosas *cosas)
{
	int		*numbers;

	cosas->k = 1;
	cosas->number_count = ft_nbr_count(args);
	numbers = (int *)malloc(sizeof(int) * cosas->number_count);
	if (!numbers)
		ft_print_error("Malloc KO\n");
	while (cosas->i < cosas->number_count)
	{
		cosas->matrix = ft_split(args->argv[cosas->k], ' ');
		if (cosas->matrix == NULL)
			ft_print_error("Malloc KO\n");
		cosas->j = 0;
		while (cosas->matrix && cosas->matrix[cosas->j] != NULL)
			numbers[cosas->i++] = ft_atoi(cosas->matrix[cosas->j++]);
		ft_free_matrix(cosas->matrix);
		cosas->k++;
	}
	return (numbers);
}
