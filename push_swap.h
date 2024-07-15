/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:42:42 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:35:51 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

/*------STRUCTS------*/

typedef struct s_stack
{
	int				value;
	int				last;
	int				first;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_hold
{
	int	*b_moves;
	int	*a_moves;
}	t_hold;

/*------CHECKERS------*/

t_stack	**convert_args(char **argv, int *size_a);
int		is_arg_number(char *str);
int		check_args(t_stack *arr, int size, char **argv);

/*------INSTRUCTIONS------*/

void	swap_one(t_stack *stack, int size, char c);
void	swap_both(t_stack *a, t_stack *b, int size_a, int size_b);
void	push_num(t_stack **s1, t_stack **s2, int *size_s1, int *size_s2);
void	rotate_one(t_stack *stack, char c);
void	rotate_both(t_stack *a, t_stack *b);
void	rrotate_one(t_stack *stack, char c);
void	rrotate_both(t_stack *a, t_stack *b);

/*------SORTING------*/

int		to_pos(int num);
int		is_ordered(t_stack *s);
int		is_ordered_b(t_stack *s);
int		find_max_value(t_stack *s, int size, int *min_ind);
int		find_min_value(t_stack *s, int size, int *min_ind);
int		find_min_index(t_stack *b, int size_b);
int		find_min(int *a_moves, int *b_moves, int size);
void	find_index(t_stack *b, int size_b, int *max, int num);
int		moves_b(int num, t_stack *b, int size_b);
int		moves_a(int size_a, int index);
void	sort_small(t_stack *a, int size_a);
void	calculator(t_stack **a, t_stack **b, int *size_a, int *size_b);
void	sorting(t_stack **a, int *size_a);
int		min_both_rot(int *a, int *b);
void	sort_b(t_stack **b, int size);
void	neg_actions(t_hold *holder, int min_ind, t_stack **a, t_stack **b);
void	pos_actions(t_hold *holder, int min_ind, t_stack **a, t_stack **b);
void	diff_actions(t_hold *holder, int min_ind, t_stack **a, t_stack **b);

/*------STACK HANDLING------*/

void	free_holder(t_hold *holder);
t_hold	*create_holder(int size_a);
t_stack	*ft_add_back(t_stack **lst, t_stack *new);
t_stack	**alloc_stack(t_stack **a, int *size_a, int *size_b);
void	ft_delone(t_stack *stack, int size);
void	ft_clear(t_stack **stack, int size);
t_stack	*ft_stack_new(int content);
t_stack	*ft_last(t_stack *lst);
t_stack	*ft_first(t_stack *lst);

#endif