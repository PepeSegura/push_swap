/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:51:44 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/29 22:28:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arguments	args;
	t_cosas		cosas;
	int			*numbers;

	args.argc = argc;
	args.argv = argv;
	ft_memset(&cosas, 0, sizeof(t_cosas));
	if (ft_parser(&args) == 0)
		ft_print_error("Invalid characters in the arguments\n");
	if (ft_nbr_count(&args) == 0)
		ft_print_error("There is no numbers\n");
	numbers = ft_store_numbers(&args, &cosas);
	ft_check_repeat(numbers, cosas.number_count);
	/*BUCLE PARA VER VALORES DEL ARRAY*/
	int i = -1;
	while (++i < cosas.number_count)
		printf("numeros[%d] -> [%d]\n", i, numbers[i]);
	/*BUCLE PARA VER VALORES DEL ARRAY*/
	system("leaks -q push_swap");
	return (0);
}
