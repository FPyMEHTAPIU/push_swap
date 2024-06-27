/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:10:39 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 16:01:39 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function just copies a stack to the temp one for the further calculations
static t_stack	**copy_stack(t_stack *stack, int size)
{
	t_stack	**arr;

	arr = (t_stack**)malloc(sizeof(t_stack*) * size);
	if (!arr)
		return (NULL);
	while (stack->last != 1)
	{
		ft_add_back(arr, stack);
		stack = stack->next;
	}
	return (arr);
}

// This function compares a number from stack with all numbers in another stack
static int	compare_num_with_stack(int num, t_stack *b, int size_b)
{
	int		j;
	int		max;
	t_stack	**temp_arr;

	j = size_b - 1;
	max = ft_last(b)->value;
	while (j >= 0 && b->first != 0)
	{
		if (max < b->value && b->value < num)
		{
			max = b->value;
			b->index = j;
		}
		j--;
		b = b->prev;
	}
	j = 0;
	temp_arr = copy_stack(b, size_b);
	while (max != ft_last(*temp_arr)->value)
	{
		if (b->index > (size_b - 1) / 2)
		{
			rotate_one(*temp_arr, 0);
			j++;
		}
		else
		{
			rrotate_one(*temp_arr, 0);
			j--;
		}
	}
	free(temp_arr);
	b->rotation = j;
	return (j);
}

//This function returns the index of element with the cheapest movement 
static int	find_min(int *indexes, int size)
{
	int	i;
	int	min_pos;
	int	min_neg;

	i = 0;
	min_pos = 0;
	min_neg = 0;
	while (i < size)
	{
		if (indexes[i] < 0)
		{
			if (min_neg > indexes[i])
				min_neg = indexes[i];
		}
		else
		{
			if (min_pos < indexes[i])
				min_pos = indexes[i];
		}
		i++;
	}
	if ((min_neg * -1) < min_pos)
		return (min_neg);
	else
		return (min_pos);
}

/* This function calculates all moves in current situation 
and returns an index of the lowest movement value */
int	calculator(t_stack *a, t_stack *b, int size_a, int size_b)
{
	int	indexes[size_a];
	int	i;
	int	min_moves_ind;

	i = size_a - 1;
	while (i >= 0)
	{
		// compare elements from 'a' to the second stack
		indexes[i] = compare_num_with_stack(a->value, b, size_b);
		i--;
	}
	// Find minimum number in array
	min_moves_ind = find_min(indexes, size_a);
	return (min_moves_ind);
}