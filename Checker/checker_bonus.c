/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:50:57 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 11:22:04 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
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

static int	read_instructions(char **instructions, t_stack **a, int *size_a, int *size_b)
{
	t_stack	**b;
	int		pb_instr;
	int		is_ordered_a;

	b = alloc_mem_stack(*size_a);
	if (!b)
		return (-1);
	pb_instr = 0;
	is_ordered_a = 0;
	while (*instructions)
	{
		if ((*instructions)[0] == 'r')
			choose_rotation(*instructions, a, b);
		else if ((*instructions)[0] == 's')
		{
			if ((*instructions)[1] == 'a')
				swap_one(*a, *size_a, 0);
			else if ((*instructions)[1] == 'b')
				swap_one(*b, *size_b, 0);
			else if ((*instructions)[1] == 's')
			{
				swap_one(*a, *size_a, 0);
				swap_one(*b, *size_b, 0);
			}
			else
				return (print_error());
		}
		else if ((*instructions)[0] == 'p')
		{
			if ((*instructions)[1] == 'a')
			{
				if (*size_a == 0)
				{
					a = alloc_mem_stack(*size_a);
					if (!a)
						return (-1);
				}	
				push_num(b, a, size_b, size_a);
			}
			else if ((*instructions)[1] == 'b')
			{
				if (*size_b == 0 && pb_instr > 0)
				{
					b = alloc_mem_stack(*size_a);
					if (!b)
						return (-1);
				}
				push_num(a, b, size_a, size_b);
				pb_instr++;
			}
			else
				return (print_error());
		}
		else
			return (print_error());
		if (*size_a > 0)
			*a = ft_first(*a);
		if (*size_b > 0)
			*b = ft_first(*b);
		instructions++;
	}
	ft_printf("size_b = %d\n", *size_b);
	if (b && *size_b > 0)
		ft_clear(b, *size_b);
	else if (b && pb_instr == 0)
		ft_clear(b, *size_b);
	if (*size_a > 0)
	{
		is_ordered_a = is_ordered(ft_first(*a));
		ft_clear(a, *size_a);
	}
	return (is_ordered_a);
}

// This funtion applies all instructions and then check is the stack 'a' sorted
void	checker(char **instructions, t_stack **a, int *size_a, int lines)
{
	int	size_b;
	int	temp_size_a;
	int is_ordered_a;

	size_b = 0;
	is_ordered_a = 0;
	if (*size_a == 1 && !instructions)
	{
		ft_printf("OK\n");
		return ;
	}
	temp_size_a = *size_a;
	if (instructions && lines > 0)
	{
		is_ordered_a = read_instructions(instructions, a, size_a, &size_b);
		if (is_ordered_a == -1)
		{
			write(2, "Error\n", 6);
			return ;
		}
		if (temp_size_a == *size_a && is_ordered_a && size_b == 0)
		{
			*size_a = 0;
			ft_printf("OK\n");
			return ;
		}
		*size_a = 0;
	}
	else
	{
		if (is_ordered(*a))
		{
			ft_printf("OK\n");
			return ;
		}
	}
	ft_printf("KO\n");
}
