/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:50:57 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/25 11:56:55 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*---
1 - print OK and return
2 - print OK, set size_a = 0 and return
3 - print Error, set size_a = 0 and return
4 - print KO and return
---*/
static int	reset_and_ret(int *size_a, int option)
{
	if (option == 1 || option == 2)
	{
		if (option == 2)
			*size_a = 0;
		ft_printf("OK\n");
		return (0);
	}
	else if (option == 3)
	{
		*size_a = 0;
		write(2, "Error\n", 6);
		return (1);
	}
	else
	{
		ft_printf("KO\n");
		return (0);
	}
}

static void	set_first(t_stack **a, t_stack **b, int size_a, int size_b)
{
	if (size_a > 0)
		*a = ft_first(*a);
	if (size_b > 0)
		*b = ft_first(*b);
}

int	*to_neg_ptr(int *size)
{
	*size *= -1;
	return (size);
}

// This function reads instructions and does those actions
static int	read_instr(char **instr, t_stack **a, int *size_a, int *size_b)
{
	t_stack	**b;

	b = alloc_mem_stack(*size_a);
	if (!b)
		return (free_a(a, size_a));
	while (*instr)
	{
		if ((*instr)[0] == 'r')
			choose_rotation(*instr, a, b);
		else if ((*instr)[0] == 's')
			choose_swap(a, b, (*instr)[1]);
		else if ((*instr)[0] == 'p')
		{
			if ((*instr)[1] == 'a')
				if (!push_to_stack(b, a, to_neg_ptr(size_b), size_a))
					return (free_a(a, size_a));
			if ((*instr)[1] == 'b')
				if (!push_to_stack(a, b, size_a, size_b))
					return (free_a(a, size_a));
		}
		set_first(a, b, *size_a, *size_b);
		instr++;
	}
	free_b(a, b, *size_a, *size_b);
	return (free_a(a, size_a));
}

// This funtion applies all instructions and then check is the stack 'a' sorted
int	checker(char **instructions, t_stack **a, int *size_a, int lines)
{
	int	size_b;
	int	temp_size_a;
	int	is_ordered_a;

	size_b = 0;
	if (*size_a == 1 && !instructions)
		return (reset_and_ret(size_a, 1));
	temp_size_a = *size_a;
	if (instructions && lines > 0)
	{
		is_ordered_a = read_instr(instructions, a, size_a, &size_b);
		if (temp_size_a == *size_a && is_ordered_a && size_b == 0)
			return (reset_and_ret(size_a, 2));
		*size_a = 0;
	}
	else if (is_ordered(*a))
		return (reset_and_ret(size_a, 1));
	return (reset_and_ret(size_a, 4));
}
