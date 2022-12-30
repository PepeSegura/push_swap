/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/30 15:33:09 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*__HEADER FILES__*/
# include "push_swap.h"
# include "libs.h"

/*__LIBFT__*/
# include "../libft/inc/libft.h"

/*__CONSTANTS__*/
# define SPACE	' '
# define ANY	-1
# define CHILD	0

# define TRUE	1
# define FALSE	0
# define LEFT	0
# define RIGHT	1

# ifndef BONUS
#  define BONUS 0
# endif

/*____LIST_NODES______

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/

/*_____MAIN_ARGUMENTS_____*/
typedef struct s_arguments {
	char		**argv;
	int			argc;
}		t_arguments;

/*__STRUCT_STORE_NUMBERS__*/
typedef struct s_cosas {
	t_arguments	args;
	char		**matrix;
	int			i;
	int			j;
	int			k;
	int			number_count;
	int			moves_count;
}		t_cosas;

/*__MAIN__*/
int		ft_parser(t_arguments *a);

/*__UTILS__*/
int		ft_matrix_len(char **matrix);
void	ft_print_error(char *str);
void	ft_check_repeat(long *numbers, int size);

/*__NUMBER_COUNT__*/
int		ft_nbr_count(t_arguments *args);
long	*ft_store_numbers(t_cosas *cosas);

#endif
