/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:08:44 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/17 00:29:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <unistd.h>

# include "stack.h"

typedef struct s_chunk
{
	int	lower_limit;
	int	upper_limit;
}	t_chunk;

typedef struct s_info
{
	int	size_a;
	int	size_b;
}		t_info;

# define A 0
# define B 1

/* algorithm.c */
void	sort_3(t_stack **stack);
void	sort_5(t_stack **a, t_stack **b, t_info *info);

/* chunks */
void	set_chunk_range(int *start, int *end, int numbers, int nb_chunks);
void	move_to_top_next_number_from_chunk(t_stack **a, int end);
void	push_number_to_stack_b(t_stack **a, t_stack **b, t_info *info);
void	move_max_number_to_stack_a(t_stack **a, t_stack **b, t_info *info);
void	sort_chunks(t_stack **a, t_stack **b, t_info *info, int chunks);
void	move_max_number_to_stack_a(t_stack **a, t_stack **b, t_info *info);
int		numbers_in_chunk(t_stack *stack, int start, int end);
int		is_current_greater_than_b(t_stack *a, t_stack *b);

/* radix */
void	radix(t_stack **a, t_stack **b, t_info *info);

/* best_cost */
void	turk_chunks(t_stack **a, t_stack **b, t_info *info, size_t chunk_size);
void	best_cost(t_stack **a, t_stack **b, t_info *info);
void	move_cheapest_a_to_b(t_stack **a, t_stack **b, t_info *info);
void	set_target_and_dist_a(t_stack **a, t_stack **b, t_info *info);
void	set_target_and_dist_b(t_stack **a, t_stack **b, t_info *info);
void	move_cheapest_b_to_a(t_stack **b, t_stack **a, t_info *info);

/* shared */
int		calc_moves_same_dir(int dist_a, int dist_b);
int		calc_moves_oposite_dir(int dist_a, int dist_b);
void	rotate_until_0_distance(t_stack **stack, int distance, int c);
void	set_pos(t_stack *a, t_stack *b);

void	push_swap(t_stack **a, t_stack **b, t_info *info);

/* parser.c */
int		choose_state(int state, char c);
void	parser(int argc, char **argv);

/* create_stack.c */
void	create_stack(t_stack **stack_a, t_info *info, char **argv);

/* moves.c */
void	push(char c, t_stack **dest, t_stack **src, t_info *info);
void	swap(t_stack **stack, char c);
void	rotate(t_stack **stack, char c);
void	rrotate(t_stack **stack, char c);

void	double_swap(t_stack **a, t_stack **b);
void	double_rotate(t_stack **a, t_stack **b);
void	double_rrotate(t_stack **a, t_stack **b);

/* tools.c */
void	print_error(char *str);
void	write_move(char *move, char type);

#endif
