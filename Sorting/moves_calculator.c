/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:10:39 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:23:36 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function calculates all moves in each position
static t_hold	*calc_moves(t_stack **a, t_stack **b, int size_a, int size_b)
{
	t_hold	*holder;
	int		i;

	holder = create_holder(size_a);
	if (!holder)
	{
		free_holder(holder);
		return (NULL);
	}
	*a = ft_last(*a);
	i = size_a - 1;
	while (i >= 0)
	{
		holder->b_moves[i] = moves_b((*a)->value, ft_last(*b), size_b);
		holder->a_moves[i] = moves_a(size_a, i);
		i--;
		(*a) = (*a)->prev;
	}
	return (holder);
}

/* This function calculates all moves in current situation 
and returns an index of the lowest movement value */
void	calculator(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int		min_moves_ind;
	t_hold	*holder;

	if (*size_b < 1)
		return ;
	holder = calc_moves(a, b, *size_a, *size_b);
	if (!holder)
		return ;
	min_moves_ind = find_min(holder->a_moves, holder->b_moves, *size_a);
	if (holder->a_moves[min_moves_ind] < 0
		&& holder->b_moves[min_moves_ind] < 0)
		neg_actions(holder, min_moves_ind, a, b);
	else if (holder->a_moves[min_moves_ind] > 0
		&& holder->b_moves[min_moves_ind] > 0)
		pos_actions(holder, min_moves_ind, a, b);
	else
		diff_actions(holder, min_moves_ind, a, b);
	free_holder(holder);
	push_num(a, b, size_a, size_b);
	ft_printf("pb\n");
	if (*size_a == 3)
		sort_b(b, *size_b);
}
