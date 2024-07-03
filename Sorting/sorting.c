/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/03 16:56:45 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	**alloc_stack(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int	size;
	int	i;

	if (*size_a >= 5)
		size = 2;
	else
		size = (*size_a) - 3;
	b = (t_stack**)malloc(sizeof(t_stack*) * ((*size_a) - 3));
	if (!b)
		return (NULL);
	//*size_b += i;
	i = 0;
	while (i++ < size)
	{
		push_num(a, b, size_a, size_b);
		ft_printf("pb\n");
	}
	return (b);
}

static int	find_max(t_stack *stack, int size)
{
	int	i;
	int	max;

	i = size - 1;
	max = stack->value;
	while (i >= 0)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->prev;
		i--;
	}
	return (max);
}

static int	find_pos_a(int num, t_stack **a, int size_a)
{
	int	max;
	int	i;
	int	value;

	max = find_max(*a, size_a);
	i = size_a - 1;
	while (i >= 0)
	{
		value = (*a)->value;
		if (max > value && num < value)
			max = value;
		(*a) = (*a)->prev;
		i--;
	}
	i = size_a - 1;
	(*a) = ft_last(*a);
	value = (*a)->value;
	while (max != value)
	{
		value = (*a)->value;
		i--;
		(*a) = (*a)->prev;
	}
	return (++i);
}

static void	set_a(t_stack **a, int size_a, int pos_a)
{
	int	i;

	*a = ft_last(*a);
	if (pos_a >= (size_a - 1) / 2)
	{
		i = size_a - 1;
		while (i >= pos_a)
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

static int	is_ordered(t_stack *a)
{
	while (a->next->first != 1)
	{
		if (a->value < a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void sorting(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int	pos_a;

	if (*size_a <= 3)
	{
		sort_small(*a, *size_a);
		return ;
	}
	b = alloc_stack(a, b, size_a, size_b);
	if (!b)
		return ;
	while (*size_a > 3)
		calculator(ft_last(*a), ft_last(*b), *size_a, *size_b);
	sorting(a, b, size_a, size_b);
	while (*size_b)
	{
		pos_a = find_pos_a(ft_last(*b)->value, a, *size_a);
		set_a(a, *size_a, pos_a);
		push_num(b, a, size_b, size_a);
		ft_printf("pa\n");
	}
	while (!is_ordered(*a))
		set_a(a, *size_a, pos_a + ((*size_a - 1) / 2) + 1);
}
