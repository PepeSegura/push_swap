/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:21 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/31 21:59:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
------------------
	STATES
------------------
	0 INIT
	1 ERR
	2 Found Space
	3 Found Symbol
	4 Found Digit
------------------
	[ *  S  +- D ]
------------------
*/

int	get_state(int x, int y)
{
	const int	states[][4] = {\
	{1, 2, 3, 4}, \
	{1, 1, 1, 1}, \
	{1, 2, 3, 4}, \
	{1, 1, 1, 4}, \
	{1, 2, 1, 4}, \
	};

	return (states[x][y]);
}

int	choose_state(int state, char c)
{
	int	pos;

	pos = 0;
	if (c == ' ')
		pos = 1;
	else if (c == '-' || c == '+')
		pos = 2;
	else if (ft_isdigit(c))
		pos = 3;
	state = get_state(state, pos);
	return (state);
}

void	evaluate(const char *str)
{
	int	i;
	int	state;

	i = 0;
	state = 0;
	while (str[i])
	{
		state = choose_state(state, str[i]);
		i++;
	}
	if (state < 2 || state == 3)
		print_error((char *)str);
}

void	parser(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	while (argv[++i])
		evaluate(argv[i]);
}
