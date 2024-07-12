/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:10:39 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/12 17:07:44 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	find_min_index(t_stack *b, int size_b)
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

// This function compares a number from stack with all numbers in another stack
static int	moves_b(int num, t_stack *b, int size_b)
{
	int		j;
	int		max;
	int		index;

	j = size_b - 1;
	index = 0;
	max = find_min_value(b, size_b, &index);
	b = ft_last(b);
	while (j >= 0 && size_b > 1)
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
	j = 0;
	while (index < size_b - 1 && index >= 0)
	{
		if (index >= (size_b - 1) / 2)
		{
			index++;
			j++;
		}
		else
		{
			index--;
			j--;
		}
	}
	return (j);
}

static int	moves_a(/*t_stack *a, */int size_a, int index)
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
	//t_calc	*holder;

	if (*size_b < 1)
		return ;
	*a = ft_last(*a);
	*b = ft_last(*b);
	i = (*size_a) - 1;
	while (i >= 0)
	{
		b_moves[i] = moves_b((*a)->value, ft_last(*b), *size_b);
		a_moves[i] = moves_a(*size_a, i);
		i--;
		(*a) = (*a)->prev;
	}
	min_moves_ind = find_min(a_moves, b_moves, *size_a);
	/*holder = malloc(sizeof(t_calc));
	if (!holder)
		return ;
	holder->a = a;
	holder->b = b;
	holder->a_moves = a_moves;
	holder->b_moves = b_moves;
	holder->min_moves_ind = min_moves_ind;*/
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
		//both_neg_actions(holder);
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
	//free(holder);
	if (*size_a == 3)
		sort_b(b, *size_b);
}
