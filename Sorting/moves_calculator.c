/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:10:39 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/05 17:00:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function just copies a stack to the temp one for the further calculations
static t_stack	**copy_stack(t_stack *stack, int size)
{
	t_stack	**arr;
	int		i;

	arr = (t_stack**)malloc(sizeof(t_stack*) * size);
	if (!arr)
		return (NULL);
	*arr = NULL;
	if (stack->first == 1 && stack->last == 1)
	{
		ft_add_back(arr, ft_stack_new(stack->value));
		return (arr);
	}
	i = 0;
	while (i < size)
	{
		ft_add_back(arr, ft_stack_new(stack->value));
		stack = stack->next;
		i++;
	}
	return (arr);
}

static int	find_max_index(t_stack *b, int size_b)
{
	int	max;
	int	i;

	max = b->index;
	i = size_b - 1;
	while (i >= 0)
	{
		if (b->index >= 0)
			max = b->index;
		b->index = 0;
		b = b->next;
		i--;
	}
	return (max);
}

// This function compares a number from stack with all numbers in another stack
static int	moves_b(int num, t_stack *b, int size_b)
{
	int		j;
	int		max;
	t_stack	**temp_arr;
	int		index;

	j = size_b - 1;
	max = ft_last(b)->value;
	while (j >= 0)
	{
		if (max < b->value && b->value < num)
		{
			max = b->value;
			b->index = j;
		}
		else
			b->index = -1;
		j--;
		b = b->prev;
	}
	j = 0;
	temp_arr = copy_stack(ft_first(b), size_b);
	index = find_max_index(b, size_b);
	while (max != ft_last(*temp_arr)->value)
	{
		if (index > (size_b - 1) / 2)
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
	ft_clear(temp_arr);
	return (j);
}

static int	moves_a(t_stack *a, int size_a, int index)
{
	t_stack	**temp;
	int		moves;

	moves = 0;
	temp = copy_stack(ft_first(a), size_a);
	while (ft_last(*temp)->value != a->value)
	{
		if (index > (size_a - 1) / 2)
		{
			rotate_one(*temp, 0);
			moves++;
		}
		else
		{
			rrotate_one(*temp, 0);
			moves--;
		}
	}
	ft_clear(temp);
	return (moves);
}

static int	to_pos(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

//This function returns the index of element with the cheapest movement 
static int	find_min(int *a_moves, int *b_moves, int size)
{
	int	i;
	int	min;
	int	min_ind;

	i = size - 1;
	min = to_pos(a_moves[i]) + to_pos(b_moves[i]);
	min_ind = i;
	while (i >= 0)
	{
		if (min > (to_pos(a_moves[i]) + to_pos(b_moves[i])))
		{
			min = to_pos(a_moves[i]) + to_pos(b_moves[i]);
			min_ind = i;
		}
		i--;
	}
	return (min_ind);
}
static int min_both_rot(int *a, int *b)
{
	int	both_moves;

	both_moves = 0;
	if (to_pos(*a) >= to_pos(*b))
	{
		both_moves = to_pos(*a) - to_pos(*b);
		(*a) -= (*b);
	}
	else
	{
		both_moves = to_pos(*b) - to_pos(*a);
		(*b) -= (*a);
	}
	return (both_moves);
}
/* This function calculates all moves in current situation 
and returns an index of the lowest movement value */
void	calculator(t_stack *a, t_stack *b, int *size_a, int *size_b)
{
	int	b_moves[*size_a];
	int	a_moves[*size_a];
	int	i;
	int	min_moves_ind;

	a = ft_last(a);
	i = (*size_a) - 1;
	if (*size_b < 1)
		return ;
	while (i >= 0)
	{
		// compare elements from 'a' to the second stack
		b_moves[i] = moves_b(a->value, ft_last(b), *size_b);
		a_moves[i] = moves_a(a, *size_a, i) + 1;
		i--;
		a = a->prev;
	}
	// Find minimum number in array
	min_moves_ind = find_min(a_moves, b_moves, *size_a);
	a = ft_last(a);
	i = (*size_a) - 1;
	while (i-- != min_moves_ind)
		a = a->prev;
	if (a_moves[min_moves_ind] < 0 && b_moves[min_moves_ind] < 0)
	{
		// Do subtraction max - min and then do rest rra/rrb
		i = min_both_rot(&a_moves[min_moves_ind], &b_moves[min_moves_ind]);
		while (i--)
			rrotate_both(a, b);
		i = a_moves[min_moves_ind];
		while (i--)
			rrotate_one(a, 'a');
		i = b_moves[min_moves_ind];
		while (i--)
			rrotate_one(b, 'b');
	}
	else if (a_moves[min_moves_ind] > 0 && b_moves[min_moves_ind] > 0)
	{
		// Do subtraction max - min and then do rest ra/rb
		i = min_both_rot(&a_moves[min_moves_ind], &b_moves[min_moves_ind]);
		while (i--)
			rotate_both(a, b);
		i = a_moves[min_moves_ind];
		while (i--)
			rotate_one(a, 'a');
		i = b_moves[min_moves_ind];
		while (i--)
			rotate_one(b, 'b');
	}
	else
	{
		i = b_moves[min_moves_ind];
		if (i < 0)
		{
			i *= -1;
			while (i--)
				rrotate_one(b, 'b');
		}
		else
		{
			while (i--)
				rotate_one(b, 'b');
		}
		i = a_moves[min_moves_ind];
		if (i < 0)
		{
			i *= -1;
			while (i--)
				rrotate_one(a, 'b');
		}
		else
		{
			while (i--)
				rotate_one(a, 'b');
		}
	}
	push_num(&a, &b, size_a, size_b);
	ft_printf("pb\n");
	// TODO: Check order when size_a == 3 after push!!!
}
