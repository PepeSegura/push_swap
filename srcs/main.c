/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 01:28:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_numbers(t_stack **stack_a, t_info *info, const char *str);

int	main(int argc, char **argv)
{
	t_info	info = {.size_a = 0, .size_b = 0};
	static t_stack	*a;
	static t_stack	*b;

	parser(argc, argv);
	create_stack(&a, &info, argv);

	print_stack(a);

	(void)a;
	(void)b;
	return (0);
}
