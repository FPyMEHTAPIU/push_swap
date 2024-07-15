/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:21:07 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 17:58:35 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// That function computes how many steps do we need to reach an expected index
static int	calc_moves_in_ind(int size_b, int index)
{
	int	moves;

	moves = 0;
	while (index < size_b - 1 && index >= 0)
	{
		if (index >= (size_b - 1) / 2)
		{
			index++;
			moves++;
		}
		else
		{
			index--;
			moves--;
		}
	}
	return (moves);
}

// This function set numbers' indexes that less than number
void	find_index(t_stack *b, int size_b, int *max, int num)
{
	int	j;

	j = size_b - 1;
	b = ft_last(b);
	while (j >= 0 && size_b > 1)
	{
		if (*max < b->value && b->value < num)
		{
			*max = b->value;
			b->index = j;
		}
		else
			b->index = -1;
		j--;
		b = b->prev;
	}
}

// This function compares a number from stack with all numbers in another stack
int	moves_b(int num, t_stack *b, int size_b)
{
	int		j;
	int		max;
	int		index;

	index = 0;
	max = find_min_value(b, size_b, &index);
	find_index(b, size_b, &max, num);
	if (max == find_min_value(b, size_b, &index))
	{
		b = ft_last(b);
		j = size_b - 1;
		while (j-- < index)
			b = b->prev;
		b->index = index;
		if (num < max)
			index--;
	}
	else if (max > num)
		max = find_max_value(b, size_b, &index);
	else
		index = find_min_index(b, size_b);
	return (calc_moves_in_ind(size_b, index));
}

// This function calculates moves to reach suitable position of stack 'a'
int	moves_a(int size_a, int index)
{
	int		moves;

	moves = 0;
	while (index < size_a - 1 && index >= 0)
	{
		if (index >= (size_a - 1) / 2)
		{
			moves++;
			index++;
		}
		else
		{
			moves--;
			index--;
		}
	}
	return (moves);
}
