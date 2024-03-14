/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:48:02 by psegura-          #+#    #+#             */
/*   Updated: 2024/03/14 03:25:57 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_chunk
{
	int lower_limit;
	int upper_limit;
}	t_chunk;

t_chunk *define_chunks(int stack_size, int nbr_chunks)
{
	t_chunk	*chunks;
	int		i;

	chunks = ft_calloc(nbr_chunks + 1, sizeof(t_chunk));
	i = 0;
	while (i < nbr_chunks)
	{
		chunks[i].lower_limit = i * (stack_size / nbr_chunks);
		chunks[i].upper_limit = (i + 1) * (stack_size / nbr_chunks) - 1;
        if (i == nbr_chunks - 1)
            chunks[i].upper_limit = stack_size - 1;
		i++;
	}
	return (chunks);
}

int	is_number_on_chunk(int number, t_chunk chunk)
{
	return (number >= chunk.lower_limit && number <= chunk.upper_limit);
}

int	ammount_of_numbers_in_chunk(t_stack *stack, t_chunk chunk)
{
	while (stack)
	{
		if (is_number_on_chunk(stack->index, chunk))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	set_pos(t_stack *a, t_stack *b)
{
	int	pos;

	pos = 0;
	while (a)
	{
		a->pos = pos;
		pos++;
		a = a->next;
	}
	pos = 0;
	while (b)
	{
		b->pos = pos;
		pos++;
		b = b->next;
	}
}

int		get_target(t_stack *a, int index_b, int tmp_index, int tmp_pos)
{
	const t_stack	*aux = a;
	while (a)
	{
		if (index_b < a->index && tmp_index > a->index)
		{
			tmp_index = a->index;
			tmp_pos = a->pos;
		}
		a = a->next;
	}
	if (tmp_index < INT_MAX)
		return (tmp_pos);
	while (aux)
	{
		if (tmp_index > aux->index)
		{
			tmp_index = aux->index;
			tmp_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (tmp_pos);
}

void	set_target(t_stack *a, t_stack *b)
{
	// int	tmp_index;
	int	tmp_pos;

	tmp_pos = 0;
	while (b)
	{
		tmp_pos = get_target(a, b->index, INT_MAX, tmp_pos);
		b->target = tmp_pos;
		b = b->next;
	}
}

void	set_dist_a(t_stack *stack, t_info *info)
{
	while (stack)
	{
		stack->dist_a = stack->target;
		if (stack->target > info->size_a / 2)
			stack->dist_a = (info->size_a - stack->target) * -1;
		stack = stack->next;
	}
}

void	set_dist_b(t_stack *stack, t_info *info)
{
	while (stack)
	{
		stack->dist_b = stack->pos;
		if (stack->pos > info->size_b / 2)
			stack->dist_b = (info->size_b - stack->pos) * -1;
		stack = stack->next;
	}
}

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;


int	calc_moves_same_dir(int dist_a, int dist_b)
{
	const int	abs_a = abs(dist_a);
	const int	abs_b = abs(dist_b);
	int			max;

	max = abs_a;
	if (abs_a < abs_b)
		max = abs_b;
	return (max);
}

int	calc_moves_oposite_dir(int dist_a, int dist_b)
{
	return (abs(dist_a) + abs(dist_b));
}

#define A 0
#define B 1

void	rotate_until_0_distance(t_stack **stack, int distance, int c)
{
	if (distance > 0)
	{
		while (distance > 0)
		{
			rotate(stack, c);
			distance--;	
		}
	}
	else if (distance < 0)
	{
		while (distance < 0)
		{
			rrotate(stack, c);
			distance++;
		}
	}
}

void	exec_move(t_stack **a, t_stack **b, t_info *info, int dist[2])
{
	if (dist[A] > 0 && dist[B] > 0)
	{
		while (dist[A] > 0 && dist[B] > 0)
		{
			dist[A]--;
			dist[B]--;
			double_rotate(a, b);
		}
	}
	else if (dist[A] < 0 && dist[B] < 0)
	{
		while (dist[A] < 0 && dist[B] < 0)
		{
			dist[A]++;
			dist[B]++;
			double_rrotate(a, b);
		}
	}
	rotate_until_0_distance(a, dist[A], 'a');
	rotate_until_0_distance(b, dist[B], 'b');
	if (*b)
		push('a', a, b, info);
}

void	locate_cheapest_move(t_stack **a, t_stack **b, t_info *info)
{
	(void)info, (void)a;
	const t_stack	*stack_aux = *b;
	int	cheapest;
	int	aux;
	int dist[2];
	aux = 0;
	while (stack_aux)
	{
		cheapest = info->size_a + info->size_b;
		if (stack_aux->dist_a >= 0 && stack_aux->dist_b >= 0) // 2UP
			aux = calc_moves_same_dir(stack_aux->dist_a, stack_aux->dist_b);
		else if (stack_aux->dist_a < 0 && stack_aux->dist_b < 0) //2 DOWN
			aux = calc_moves_same_dir(stack_aux->dist_a, stack_aux->dist_b);
		else if (stack_aux->dist_a < 0 && stack_aux->dist_b >= 0) //A DOWN B UP
			aux = calc_moves_oposite_dir(stack_aux->dist_a, stack_aux->dist_b);
		else if (stack_aux->dist_a >= 0 && stack_aux->dist_b < 0) //A UP B DOWN
			aux = calc_moves_oposite_dir(stack_aux->dist_a, stack_aux->dist_b);
		// printf("Cost to move: [%d]\t-> [%d]\n", stack_aux->content, aux);
		if (aux < cheapest)
		{
			cheapest = aux;
			dist[A] = stack_aux->dist_a;
			dist[B] = stack_aux->dist_b;
		}
		stack_aux = stack_aux->next;
	}
	exec_move(a, b, info, dist);
}

void	move_index_to_top(t_stack **a, t_info *info)
{
	const t_stack	*stack_aux = *a;
	int				pos;

	pos = 0;
	while (stack_aux)
	{
		if (stack_aux->index == 0)
			break ;
		pos++;
		stack_aux = stack_aux->next;
	}
	if (pos < info->size_a / 2)
	{
		while (pos-- > 0)
			rotate(a, 'a');
	}
	else
	{
		while (pos-- > 0)
			rrotate(a, 'a');
	}
}

#define N_CHUNKS 3

void	best_cost(t_stack **a, t_stack **b, t_info *info)
{
	t_chunk *chunks;
	int		i;

	chunks = define_chunks(info->size_a, N_CHUNKS);
	i = 0;
	while (info->size_a > 3)
	{
		if (ammount_of_numbers_in_chunk(*a, chunks[i]) == 0 && i < N_CHUNKS)
			i++;
		move_to_top_next_number_from_chunk(a, chunks[i].upper_limit);
		push_number_to_stack_b(a, b, info);
	}
	sort_3(a);
	while (info->size_b > 0)
	{
		set_pos(*a, *b);
		set_target(*a, *b);
		set_dist_a(*b, info);
		set_dist_b(*b, info);
		// ft_dprintf(2, "STACK_AAAAA\n");
		// stack_iteri(*a, print_data);
		// ft_dprintf(2, "STACK_BBBBB\n");
		// stack_iteri(*b, print_data);
		locate_cheapest_move(a, b, info);
	}
	move_index_to_top(a, info);
	// stack_iteri(*a, print_data);
	// stack_iteri(*b, print_data);
	// while (info->size_b > 0)
	// {
	// 	move_max_number_to_stack_a(a, b, info);
	// }
	free(chunks);
}
