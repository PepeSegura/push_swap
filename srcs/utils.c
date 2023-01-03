/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:24 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/03 16:58:26 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

// void	ft_print_list(t_list *stack, char *str)
// {
// 	int	i;

// 	i = 0;
// 	printf("Stack_%s:\n", str);
// 	while (stack != NULL)
// 	{
// 		printf("\tPos: [%i] Content: [%ld]\n", i, (long)stack->content);
// 		usleep(100000);
// 		stack = stack->next;
// 		i++;
// 	}
// }
