/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:47:58 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:28:46 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function returns max value in stack
int	find_max_value(t_stack *s, int size, int *min_ind)
{
	int	max;
	int	i;

	s = ft_first(s);
	max = s->value;
	i = 0;
	while (i < size)
	{
		if (max < s->value)
		{
			max = s->value;
			*min_ind = i;
		}
		i++;
		s = s->next;
	}
	return (max);
}

// This function returns min value in stack
int	find_min_value(t_stack *s, int size, int *min_ind)
{
	int	min;
	int	i;

	s = ft_first(s);
	min = s->value;
	i = 0;
	while (i < size)
	{
		if (min > s->value)
		{
			min = s->value;
			*min_ind = i;
		}
		i++;
		s = s->next;
	}
	return (min);
}

// This function returns the last suitable index in stack
int	find_min_index(t_stack *b, int size_b)
{
	int	min;
	int	i;

	b = ft_last(b);
	min = b->index;
	i = size_b - 1;
	while (i >= 0)
	{
		if (b->index >= 0)
			min = b->index;
		b->index = 0;
		b = b->prev;
		i--;
	}
	return (min);
}

// This function calculates total amount of 'a' and 'b' moves
static int	set_moves(int *a_moves, int *b_moves, int i)
{
	int	moves;

	if (a_moves[i] > 0 && b_moves[i] > 0)
	{
		if (a_moves[i] >= b_moves[i])
			moves = a_moves[i];
		else
			moves = b_moves[i];
	}
	else if (a_moves[i] < 0 && b_moves[i] < 0)
	{
		if (a_moves[i] <= b_moves[i])
			moves = to_pos(a_moves[i]);
		else
			moves = to_pos(b_moves[i]);
	}
	else
		moves = to_pos(a_moves[i]) + to_pos(b_moves[i]);
	return (moves);
}

//This function returns the index of element with the cheapest movement 
int	find_min(int *a_moves, int *b_moves, int size)
{
	int	i;
	int	max;
	int	min_ind;
	int	moves;

	i = size - 1;
	max = to_pos(a_moves[i]) + to_pos(b_moves[i]);
	min_ind = i;
	while (i >= 0)
	{
		moves = set_moves(a_moves, b_moves, i);
		if (max > moves)
		{
			max = moves;
			min_ind = i;
		}
		i--;
	}
	return (min_ind);
}
