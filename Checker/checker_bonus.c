/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:50:57 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 14:11:46 by msavelie         ###   ########.fr       */
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

static t_stack	**alloc_mem_stack(int size)
{
	t_stack	**s;

	s = (t_stack **)malloc(sizeof(t_stack *) * size);
	if (!s)
		return (NULL);
	*s = NULL;
	return (s);
}

static int	free_b(t_stack **b, int size_b, int pb_instr)
{
	if (b && size_b > 0)
		ft_clear(b, size_b);
	else if (b && pb_instr == 0)
		ft_clear(b, size_b);
	return (0);
}

static int	free_a(t_stack **a, int size_a)
{
	int	is_ordered_a;

	is_ordered_a = 0;
	if (size_a > 0)
	{
		is_ordered_a = is_ordered(ft_first(*a));
		ft_clear(a, size_a);
	}
	return (is_ordered_a);
}

static int	check_capacity(t_stack **s, int size_s, int pb_instr, int size_a)
{
	if (size_a == -1)
	{
		if (size_s == 0)
		{
			s = alloc_mem_stack(size_s);
			if (!s)
				return (0);
		}
	}
	else
	{
		if (size_s == 0 && pb_instr > 0)
		{
			s = alloc_mem_stack(size_a);
			if (!s)
				return (0);
		}
	}
	return (1);
}

static void	set_first(t_stack **a, t_stack **b, int size_a, int size_b)
{
	if (size_a > 0)
		*a = ft_first(*a);
	if (size_b > 0)
		*b = ft_first(*b);
}

// This function reads instructions and does those actions
static int	read_instructions(char **instructions, t_stack **a, int *size_a, int *size_b)
{
	t_stack	**b;
	int		pb_instr;

	b = alloc_mem_stack(*size_a);
	if (!b)
		return (-1);
	pb_instr = 0;
	while (*instructions)
	{
		if ((*instructions)[0] == 'r')
			choose_rotation(*instructions, a, b);
		else if ((*instructions)[0] == 's')
			choose_swap(a, b, (*instructions)[1]);
		else if ((*instructions)[0] == 'p')
		{
			if ((*instructions)[1] == 'a')
			{
				if (!check_capacity(a, *size_a, pb_instr, -1))
					return (free_b(b, *size_b, pb_instr));
				push_num(b, a, size_b, size_a);
			}
			else if ((*instructions)[1] == 'b')
			{
				if (!check_capacity(b, *size_b, pb_instr, *size_a))
					return (free_a(a, *size_a));
				push_num(a, b, size_a, size_b);
				pb_instr++;
			}
		}
		set_first(a, b, *size_a, *size_b);
		instructions++;
	}
	free_b(b, *size_b, pb_instr);
	return (free_a(a, *size_a));
}

// This funtion applies all instructions and then check is the stack 'a' sorted
int	checker(char **instructions, t_stack **a, int *size_a, int lines)
{
	int	size_b;
	int	temp_size_a;
	int is_ordered_a;

	size_b = 0;
	is_ordered_a = 0;
	if (*size_a == 1 && !instructions)
		return (reset_and_ret(size_a, 1));
	temp_size_a = *size_a;
	if (instructions && lines > 0)
	{
		is_ordered_a = read_instructions(instructions, a, size_a, &size_b);
		if (is_ordered_a == -1)
			return (reset_and_ret(size_a, 3));
		else if (temp_size_a == *size_a && is_ordered_a && size_b == 0)
			return (reset_and_ret(size_a, 2));
		*size_a = 0;
	}
	else if (is_ordered(*a))
		return (reset_and_ret(size_a, 1));
	return (reset_and_ret(size_a, 4));
}
