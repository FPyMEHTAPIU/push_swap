/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:42:21 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/12 17:05:27 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int min_both_rot(int *a, int *b)
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

//TODO: put 2 index arrays, min_moves_ind and stacks into new struct and pass that struct as a parameter

// Do subtraction max - max and then do rest rra/rrb
void	both_neg_actions(t_calc *holder)
{
	int	i;

	i = to_pos(min_both_rot(&(holder->a_moves[holder->min_moves_ind]), 
		&(holder->b_moves[holder->min_moves_ind])));
	while (i--)
		rrotate_both(*(holder->a), *(holder->b));
	i = to_pos(holder->a_moves[holder->min_moves_ind]);
	while (i--)
		rrotate_one(*(holder->a), 'a');
	i = to_pos(holder->a_moves[holder->min_moves_ind]);
	while (i--)
		rrotate_one(*(holder->b), 'b');
}