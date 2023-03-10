/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/03 17:27:52 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*__HEADER FILES__*/
# include "push_swap.h"
# include "libs.h"

/*__LIBFT__*/
# include "../libft/inc/libft.h"

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
	int			stack_a_size;
	int			stack_b_size;
}		t_cosas;

/*__CREATE_STACKS__*/
t_list	*ft_create_stacks(long *numbers, t_cosas *c, t_list *stack_a);

/*__MOVES_A__*/
void	swap_a(t_list **stack_a);
void	push_a(t_list **stack_a, t_list **stack_b, t_cosas *cosas);
void	rotate_a(t_list **stack_a);
void	rrotate_a(t_list **stack_a);

/*__MOVES_B__*/
void	swap_b(t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b, t_cosas *cosas);
void	rotate_b(t_list **stack_b);
void	rrotate_b(t_list **stack_b);

/*__MOVES_AB__*/
void	swap_ab(t_list **stack_a, t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	rrotate_ab(t_list **stack_a, t_list **stack_b);

/*__NBR_COUNT__*/
int		ft_already_checked(int number, long *numbers, int i);
void	ft_check_repeat(long *numbers, int size);

/*__PARSER__*/
int		ft_is_nbr_space(char *str);
int		ft_parser(t_arguments *a);
int		ft_nbr_count(t_arguments *args);
long	*ft_store_numbers(t_cosas *c);

/*__SORT_LIST__*/
void	ft_choose_algorithm(t_list **stack_a, t_list **stack_b, t_cosas *cosas);
void	ft_sort_max_3(t_list **stack_a);
void	ft_sort_max_10(t_list **stack_a, t_list **stack_b, t_cosas *cosas);
void	ft_sort_max_500(t_list **stack_a, t_list **stack_b, t_cosas *cosas);

/*__TAB_UTILS__*/
void	ft_bubble_sort(long *tab, int size);
void	ft_reorder_tab(long *tab, long *numbers, long *result, int size);
void	ft_copy_tab(long *tab, long *numbers, int size);
void	ft_sort_tab(long *numbers, int size);

/*__TOOLS__*/
int		ft_is_ordered(t_list *stack_a);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		find_num(t_list *stack, int num);
int		ft_max_bites(t_list *list);

/*__UTILS__*/
int		ft_matrix_len(char **matrix);
void	ft_print_error(char *str);
void	ft_print_list(t_list *stack, char *str);

#endif
