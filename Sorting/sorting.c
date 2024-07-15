/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:35:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This function is looking for the suitable place for 
the top number from stack 'b' in stack 'a' */
static int	find_pos_a(int num, t_stack **a, int size_a)
{
	int	max;
	int	i;
	int	value;

	*a = ft_last(*a);
	max = find_max_value(*a, size_a, &i);
	i = size_a - 1;
	while (i >= 0)
	{
		value = (*a)->value;
		if (max > value && num < value)
			max = value;
		(*a) = (*a)->prev;
		i--;
	}
	if (max < num)
		return (-1);
	i = size_a - 1;
	(*a) = ft_last(*a);
	while (max != (*a)->value)
	{
		i--;
		(*a) = (*a)->prev;
	}
	return (i);
}

/* This function rotates stack 'a' as many times as we need 
to reach the suitable number at the top of the stack 'a' */
static void	set_a(t_stack **a, int size_a, int pos_a)
{
	int	i;

	*a = ft_last(*a);
	if (pos_a == -1)
		return ;
	if (pos_a >= (size_a - 1) / 2)
	{
		i = size_a - 1;
		while (i > pos_a)
		{
			rotate_one(*a, 'a');
			i--;
		}
	}
	else
	{
		i = 0;
		while (i <= pos_a)
		{
			rrotate_one(*a, 'a');
			i++;
		}
	}
}

// This function moves sorted numbers from stack 'b' back to stack 'a'
static int	push_back_to_a(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int	pos_a;

	*b = ft_last(*b);
	*a = ft_last(*a);
	pos_a = find_pos_a((*b)->value, a, *size_a);
	set_a(a, *size_a, pos_a);
	push_num(b, a, size_b, size_a);
	ft_printf("pa\n");
	return (pos_a);
}

// Set already sorted 'a' in ascending order (the smallest element at the top)
static void	ordering_a(t_stack **a, int size_a, int pos_a)
{
	if (pos_a >= (size_a - 1) / 2)
		while (!is_ordered(ft_first(*a)))
			rotate_one(*a, 'a');
	else
		while (!is_ordered(ft_first(*a)))
			rrotate_one(*a, 'a');
}

// This is the main sorting function with the entire sorting logic
void	sorting(t_stack **a, int *size_a)
{
	t_stack	**b;
	int		size_b;
	int		pos_a;

	size_b = 0;
	if (is_ordered(*a))
		return ;
	if (*size_a <= 3)
	{
		sort_small(*a, *size_a);
		return ;
	}
	b = alloc_stack(a, size_a, &size_b);
	if (!b)
		return ;
	while (*size_a > 3)
		calculator(a, b, size_a, &size_b);
	sort_small(*a, *size_a);
	while (size_b)
		pos_a = push_back_to_a(a, b, size_a, &size_b);
	ordering_a(a, *size_a, pos_a);
}
