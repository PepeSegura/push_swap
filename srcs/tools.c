/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:35:37 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/16 23:49:44 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef BONUS

void	print_error(char *str)
{
	ft_dprintf(2, "Error: %s\n", str);
	exit(EXIT_FAILURE);
}

void	write_move(char *move, char type)
{
	int	res;

	res = write(1, move, ft_strlen(move));
	res = write(1, &type, 1);
	res = write(1, "\n", 1);
	(void)res;
}
#else

void	print_error(char *str)
{
	(void)str;
	ft_dprintf(2, "Error\n");
	exit(EXIT_FAILURE);
}

void	write_move(char *move, char type)
{
	(void)move, (void)type;
}
#endif
