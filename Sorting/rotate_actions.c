/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:42:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/18 15:48:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Do subtraction max - min and then do rest rra/rrb
void	neg_actions(t_hold *holder, int min_ind, t_stack **a, t_stack **b)
{
	int	i;

	i = to_pos(min_both_rot(&(holder->a_moves[min_ind]),
				&(holder->b_moves[min_ind])));
	while (i--)
		rrotate_both(*a, *b, 'r');
	i = to_pos(holder->a_moves[min_ind]);
	while (i--)
		rrotate_one(*a, 'a');
	i = to_pos(holder->b_moves[min_ind]);
	while (i--)
		rrotate_one(*b, 'b');
}

// Do subtraction max - min and then do rest ra/rb
void	pos_actions(t_hold *holder, int min_ind, t_stack **a, t_stack **b)
{
	int	i;

	i = to_pos(min_both_rot(&(holder->a_moves[min_ind]),
				&(holder->b_moves[min_ind])));
	while (i--)
		rotate_both(*a, *b, 'r');
	i = to_pos(holder->a_moves[min_ind]);
	while (i--)
		rotate_one(*a, 'a');
	i = to_pos(holder->b_moves[min_ind]);
	while (i--)
		rotate_one(*b, 'b');
}

// Do ra/rra/rb/rrb if they are different
void	diff_actions(t_hold *holder, int min_ind, t_stack **a, t_stack **b)
{
	int	i;

	i = holder->b_moves[min_ind];
	if (i < 0)
	{
		i *= -1;
		while (i--)
			rrotate_one(*b, 'b');
	}
	else
		while (i--)
			rotate_one(*b, 'b');
	i = holder->a_moves[min_ind];
	if (i < 0)
	{
		i *= -1;
		while (i--)
			rrotate_one(*a, 'a');
	}
	else
		while (i--)
			rotate_one(*a, 'a');
}

// This function returns value of rr/rrr and changes the value of rest rotations
int	min_both_rot(int *a, int *b)
{
	int	both_moves;

	both_moves = 0;
	if (to_pos(*a) >= to_pos(*b))
	{
		both_moves = to_pos(*b);
		(*a) -= (*b);
		*b = 0;
	}
	else
	{
		both_moves = to_pos(*a);
		(*b) -= (*a);
		*a = 0;
	}
	return (both_moves);
}

// This function rotates stack 'b' until it has the greatest element at the top
void	sort_b(t_stack **b, int size)
{
	int	min_ind;

	min_ind = 0;
	find_max_value(*b, size, &min_ind);
	while (!is_ordered_b(ft_first(*b)))
	{
		if (min_ind >= (size - 1) / 2)
			rotate_one(*b, 'b');
		else
			rrotate_one(*b, 'b');
	}
}
