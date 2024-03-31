/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:23:52 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/31 19:28:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_move(char *move, t_stack **a, t_stack **b, t_info *info)
{
	if (!ft_strcmp(move, "sa\n"))
		swap(a, 'a');
	else if (!ft_strcmp(move, "sb\n"))
		swap(b, 'b');
	else if (!ft_strcmp(move, "ss\n"))
		double_swap(a, b);
	else if (!ft_strcmp(move, "pa\n"))
		push('a', a, b, info);
	else if (!ft_strcmp(move, "pb\n"))
		push('b', b, a, info);
	else if (!ft_strcmp(move, "ra\n"))
		rotate(a, 'a');
	else if (!ft_strcmp(move, "rb\n"))
		rotate(b, 'b');
	else if (!ft_strcmp(move, "rr\n"))
		double_rotate(a, b);
	else if (!ft_strcmp(move, "rra\n"))
		rrotate(a, 'a');
	else if (!ft_strcmp(move, "rrb\n"))
		rrotate(b, 'b');
	else if (!ft_strcmp(move, "rrr\n"))
		double_rrotate(a, b);
	else
		print_error(NULL);
}

void	exec_moves(t_stack **a, t_stack **b, t_info *info)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		make_move(line, a, b, info);
		free(line);
		line = NULL;
	}
}

void	check_result(t_stack **a, t_info *info)
{
	if (is_ordered(*a) && info->size_b == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	static t_info	info = {.size_a = 0, .size_b = 0};
	static t_stack	*a;
	static t_stack	*b;

	parser(argc, argv);
	create_stack(&a, &info, argv);
	exec_moves(&a, &b, &info);
	check_result(&a, &info);
}
