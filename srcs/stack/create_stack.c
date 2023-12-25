/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:37:13 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/25 02:10:57 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_numbers(t_stack **stack_a, t_info *info, const char *str)
{
	int	i;
	int	state;
	int	prev;

	i = 0;
	state = 0;
	prev = 0;
	while (str[i])
	{
		prev = state;
		state = choose_state(state, str[i]);
		if (state == 4 && (prev == 2 || prev == 3 || prev == 0))
		{
			if (prev == 3)
				i--;
			stack_add_back(stack_a, stack_new(ft_atoi_limits(str + i)));
			info->size_a++;
		}
		i++;
	}
}

void	check_duplicates(t_stack *stack)
{
	int		current_value;
	t_stack	*temp;

	while (stack)
	{
		current_value = stack->content;
		temp = stack->next;
		while (temp)
		{
			if (temp->content == current_value)
				print_error("Duplicate numbers.");
			temp = temp->next;
		}
		stack = stack->next;
	}
}

int	count_smaller(t_stack *stack, t_stack *current)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		if (stack->content < current->content)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	add_index(t_stack **stack)
{
	t_stack	*current;

	current = (*stack);
	while (current != NULL)
	{
		current->index = count_smaller(*stack, current);
		current = current->next;
	}
}

void	create_stack(t_stack **stack_a, t_info *info, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		store_numbers(stack_a, info, argv[i]);
	check_duplicates(*stack_a);
	add_index(stack_a);
}
