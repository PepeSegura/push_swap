/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/31 19:14:53 by psegura-         ###   ########.fr       */
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
void	ft_choose_algorithm(t_list *stack_a, t_list *stack_b, t_cosas *cosas);
void	ft_sort_max_3(t_list *stack_a);
void	ft_sort_max_5(t_list *stack_a, t_list *stack_b, t_cosas *cosas);
void	ft_sort_max_100(t_list *stack_a, t_list *stack_b, t_cosas *cosas);

/*__UTILS__*/
int		ft_matrix_len(char **matrix);
void	ft_print_error(char *str);
void	ft_check_repeat(long *numbers, int size);
int		ft_is_ordered(t_list *stack_a);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		find_num(t_list *stack, int num);
void	print_stack(t_list *stack, char letter);

/*__NUMBER_COUNT__*/
int		ft_nbr_count(t_arguments *args);
long	*ft_store_numbers(t_cosas *cosas);

/*__LISTS__*/
t_list	*ft_create_stacks(long *numbers, t_cosas *c, t_list *stack_a);

/*__MOVES_A__*/
void	swap_a(t_list **stack_a);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rrotate_a(t_list **stack_a);

/*__MOVES_B__*/
void	swap_b(t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_b(t_list **stack_b);
void	rrotate_b(t_list **stack_b);

/*__MOVES_AB__*/
void	swap_ab(t_list **stack_a, t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	rrotate_ab(t_list **stack_a, t_list **stack_b);

#endif
