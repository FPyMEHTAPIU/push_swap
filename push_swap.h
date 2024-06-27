/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:42:42 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 15:56:42 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct s_stack
{
	char			stack;
	int				value;
	int				rotation; // if negative - reverse rotation
	int				index;
	int				last;
	int				first;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*------CHECKERS------*/

t_stack	**convert_args(char **argv, int *size_a);
int		is_arg_number(char *str);
int		check_args(t_stack *arr, int size, char **argv);

/*------INSTRUCTIONS------*/

void    swap_one(t_stack *stack, int size, char c);
void	swap_both(t_stack *a, t_stack *b, int size_a, int size_b);
void	push_num(t_stack **s1, t_stack **s2, int *size_s1, int *size_s2);
void	rotate_one(t_stack *stack, /*const int size,*/ char c);
void	rotate_both(t_stack *a, t_stack *b); //, int size_a, int size_b);
void 	rrotate_one(t_stack *stack, /*const int size,*/ char c);
void	rrotate_both(t_stack *a, t_stack *b); //, int size_a, int size_b);

/*------SORTING------*/

void	sort_small(t_stack *a, int size_a);
int		calculator(t_stack *a, t_stack *b, int size_a, int size_b);
void	sorting(t_stack **a, t_stack **b, int *size_a, int *size_b);

/*------STACK HANDLING------*/

void	ft_add_back(t_stack **lst, t_stack *new);
void	ft_add_front(t_stack **stack, t_stack *new);
void	ft_delone(t_stack *stack);
void	ft_clear(t_stack **stack);
t_stack	*ft_stack_new(int content);
t_stack	*ft_last(t_stack *lst);
t_stack	*ft_first(t_stack *lst);

#endif