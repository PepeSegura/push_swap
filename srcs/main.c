/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/13 22:55:43 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_info	info = {.size_a = 0, .size_b = 0};
	static t_stack	*a;
	static t_stack	*b;

	parser(argc, argv);
	create_stack(&a, &info, argv);
	// stack_iteri(a, print_data);
	// stack_iteri(b, print_data);
	push_swap(&a, &b, &info);
}
