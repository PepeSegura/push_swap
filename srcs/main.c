/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:51:44 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/30 16:15:13 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cosas		c;
	long		*numbers;
	int			i;

	i = -1;
	ft_memset(&c, 0, sizeof(t_cosas));
	c.args.argc = argc;
	c.args.argv = argv;
	if (ft_parser(&c.args) == 0)
		ft_print_error("Invalid characters in the arguments\n");
	if (ft_nbr_count(&c.args) == 0)
		ft_print_error("There is no numbers\n");
	numbers = ft_store_numbers(&c);
	ft_check_repeat(numbers, c.number_count);
	/*BUCLE PARA VER VALORES DEL ARRAY*/
	while (++i < c.number_count)
		printf("numeros[%d] -> [%ld]\n", i, numbers[i]);
	/*BUCLE PARA VER VALORES DEL ARRAY*/
	system("leaks -q push_swap");
	return (0);
}
