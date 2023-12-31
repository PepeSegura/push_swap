/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:35:37 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/31 20:11:48 by psegura-         ###   ########.fr       */
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
	write(1, move, ft_strlen(move));
	write(1, &type, 1);
	write(1, "\n", 1);
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
