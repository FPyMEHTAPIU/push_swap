/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:10:39 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/10 16:37:54 by msavelie         ###   ########.fr       */
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
		(*arr)->first = 1;
		(*arr)->last = 1;
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

static int	find_max_value(t_stack *s, int size, int *min_ind)
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

static int	find_min_value(t_stack *s, int size, int *min_ind)
{
	int	max;
	int	i;

	s = ft_first(s);
	max = s->value;
	i = 0;
	while (i < size)
	{
		if (max > s->value)
		{
			max = s->value;
			*min_ind = i;
		}
		i++;
		s = s->next;
	}
	return (max);
}

static int	find_min_index(t_stack *b, int size_b)
{
	int	max;
	int	i;

	//b = ft_first(b);
	b = ft_last(b);
	max = b->index;
	i = size_b - 1;
	while (i >= 0)
	{
		if (b->index >= 0)
			max = b->index;
		b->index = 0;
		//b = b->next;
		b = b->prev;
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
	index = 0;
	max = find_min_value(b, size_b, &index);
	temp_arr = copy_stack(ft_first(b), size_b);
	*temp_arr = ft_last(*temp_arr);
	while (j >= 0 && size_b > 1)
	{
		if (max < (*temp_arr)->value && (*temp_arr)->value < num)
		{
			max = (*temp_arr)->value;
			(*temp_arr)->index = j;
		}
		else
			(*temp_arr)->index = -1;
		j--;
		*temp_arr = (*temp_arr)->prev;
	}
	if (max == find_min_value(b, size_b, &index))
	{
		*temp_arr = ft_last(*temp_arr);
		j = size_b - 1;
		while (j-- < index)
			*temp_arr = (*temp_arr)->prev;
		(*temp_arr)->index = index;
	}
	/*while (j >= 0)
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
	}*/
	if (max > num)
		max = find_max_value(*temp_arr, size_b, &index);
	else
		index = find_min_index(*temp_arr, size_b);
	//temp_arr = copy_stack(ft_first(b), size_b);
	j = 0;
	while (max != ft_last(*temp_arr)->value)
	{
		if (index >= (size_b - 1) / 2)
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
		if (index >= (size_a - 1) / 2)
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
	int	max;
	int	min_ind;
	int	moves;

	i = size - 1;
	max = to_pos(a_moves[i]) + to_pos(b_moves[i]);
	min_ind = i;
	while (i >= 0)
	{
		if (a_moves[i] > 0 && b_moves[i] > 0)
		{
			if (a_moves[i] >= b_moves[i])
				moves = b_moves[i] + (a_moves[i] - b_moves[i]);
			else
				moves = a_moves[i] + (b_moves[i] - a_moves[i]);
		}
		else if (a_moves[i] < 0 && b_moves[i] < 0)
		{
			if (a_moves[i] <= b_moves[i])
				moves = to_pos(b_moves[i]) + (to_pos(a_moves[i]) - to_pos(b_moves[i]));
			else
				moves = to_pos(a_moves[i]) + (to_pos(b_moves[i]) - to_pos(a_moves[i]));
		}
		else
			moves = to_pos(a_moves[i]) + to_pos(b_moves[i]);
		if (max > moves)
		{
			max = moves;
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

static void	sort_b(t_stack **b, int size)
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
/* This function calculates all moves in current situation 
and returns an index of the lowest movement value */
void	calculator(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int	b_moves[*size_a];
	int	a_moves[*size_a];
	int	i;
	int	min_moves_ind;

	if (*size_b < 1)
		return ;
	*a = ft_last(*a);
	*b = ft_last(*b);
	i = (*size_a) - 1;
	while (i >= 0)
	{
		// compare elements from 'a' to the second stack
		b_moves[i] = moves_b((*a)->value, ft_last(*b), *size_b);
		a_moves[i] = moves_a((*a), *size_a, i);
		i--;
		(*a) = (*a)->prev;
	}
	// Find minimum number in array
	min_moves_ind = find_min(a_moves, b_moves, *size_a);
	*a = ft_last(*a);
	*b = ft_last(*b);
	if (a_moves[min_moves_ind] < 0 && b_moves[min_moves_ind] < 0)
	{
		// Do subtraction max - max and then do rest rra/rrb
		i = to_pos(min_both_rot(&a_moves[min_moves_ind], &b_moves[min_moves_ind]));
		while (i--)
			rrotate_both(*a, *b);
		i = to_pos(a_moves[min_moves_ind]);
		while (i--)
			rrotate_one(*a, 'a');
		i = to_pos(b_moves[min_moves_ind]);
		while (i--)
			rrotate_one(*b, 'b');
	}
	else if (a_moves[min_moves_ind] > 0 && b_moves[min_moves_ind] > 0)
	{
		// Do subtraction max - max and then do rest ra/rb
		i = to_pos(min_both_rot(&a_moves[min_moves_ind], &b_moves[min_moves_ind]));
		while (i--)
			rotate_both(*a, *b);
		i = to_pos(a_moves[min_moves_ind]);
		while (i--)
			rotate_one(*a, 'a');
		i = to_pos(b_moves[min_moves_ind]);
		while (i--)
			rotate_one(*b, 'b');
	}
	else
	{
		i = b_moves[min_moves_ind];
		if (i < 0)
		{
			i *= -1;
			while (i--)
				rrotate_one(*b, 'b');
		}
		else
		{
			while (i--)
				rotate_one(*b, 'b');
		}
		i = a_moves[min_moves_ind];
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
	push_num(a, b, size_a, size_b);
	ft_printf("pb\n");
	if (*size_a == 3)
		sort_b(b, *size_b);
}
