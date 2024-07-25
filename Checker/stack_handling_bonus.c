/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:50:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/25 11:54:16 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	**alloc_mem_stack(int size)
{
	t_stack	**s;

	s = (t_stack **)malloc(sizeof(t_stack *) * size);
	if (!s)
		return (NULL);
	*s = NULL;
	return (s);
}

int	check_pushed_b(t_stack *s, int size)
{
	int	i;

	i = 0;
	s = ft_last(s);
	while (i < size)
	{
		if (s->was_pushed == 1)
			return (1);
		i++;
		s = s->prev;
	}
	return (0);
}

int	free_b(t_stack **a, t_stack **b, int size_a, int size_b)
{
	if (size_b == 0 && !check_pushed_b(*a, size_a))
		free(b);
	else if (size_b == 0)
		return (0);
	else if (b && size_b > 0)
		ft_clear(b, size_b);
	return (0);
}

int	free_a(t_stack **a, int *size_a)
{
	int	is_ordered_a;

	is_ordered_a = 0;
	if (*size_a > 0)
	{
		is_ordered_a = is_ordered(ft_first(*a));
		ft_clear(a, *size_a);
	}
	return (is_ordered_a);
}

int	check_capacity(t_stack **s, int size_s, int pb_instr, int *size_a)
{
	if (*size_a < 0)
	{
		*size_a *= -1;
		if (size_s == 0)
		{
			s = alloc_mem_stack(*size_a);
			if (!s)
				return (0);
		}
	}
	else
	{
		if (size_s == 0 && pb_instr > 0)
		{
			s = alloc_mem_stack(*size_a);
			if (!s)
				return (0);
		}
	}
	return (1);
}
