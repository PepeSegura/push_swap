/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:51:44 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/02 20:47:46 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cosas		c;
	long		*numbers;
	t_list		*stack_a;
	t_list		*stack_b;

	ft_memset(&c, 0, sizeof(t_cosas));
	c.args.argc = argc;
	c.args.argv = argv;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_parser(&c.args) == 0)
		ft_print_error("Invalid characters in the arguments\n");
	if (ft_nbr_count(&c.args) == 0)
		ft_print_error("There is no numbers\n");
	numbers = ft_store_numbers(&c);
	ft_check_repeat(numbers, c.number_count);
	ft_sort_tab(numbers, c.number_count);
	stack_a = ft_create_stacks(numbers, &c, stack_a);
	ft_print_list(stack_a, "A");
	ft_choose_algorithm(stack_a, stack_b, &c);
	system("leaks -q push_swap");
	return (0);
}

	// print_stack(stack_a, 'A');
	// print_stack(stack_b, 'B');
/*
swap_a(&stack_a);
push_a(&stack_a, &stack_b);
rotate_a(&stack_a);
rrotate_a(&stack_a);

swap_b(&stack_b);
push_b(&stack_a, &stack_b);
rotate_b(&stack_b);
rrotate_b(&stack_b);

swap_ab(&stack_a, &stack_b);
rotate_ab(&stack_a, &stack_b);
rrotate_ab(&stack_a, &stack_b);
*/
