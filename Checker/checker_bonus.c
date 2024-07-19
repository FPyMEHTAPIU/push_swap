/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:50:57 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/19 16:17:09 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	read_instructions(char **instructions, t_stack **a, int *size_a)
{
	t_stack	**b;
	int		size_b;

	size_b = 0;
	b = (t_stack **)malloc(sizeof(t_stack *) * (*size_a));
	if (!b)
		return (-1);
	*b = NULL;
	while (*instructions)
	{
		if ((*instructions)[0] == 'r')
			choose_rotation(*instructions, a, b);
		else if ((*instructions)[0] == 's')
		{
			if ((*instructions)[1] == 'a')
				swap_one(*a, *size_a, 0);
			else if ((*instructions)[1] == 'b')
				swap_one(*b, size_b, 0);
			else if ((*instructions)[1] == 's')
			{
				swap_one(*a, *size_a, 0);
				swap_one(*b, size_b, 0);
			}
			else
			{
				write(2, "Error\n", 6);
				return (-1);
			}
		}
		else if ((*instructions)[0] == 'p')
		{
			if ((*instructions)[1] == 'a')
				push_num(b, a, &size_b, size_a);
			else if ((*instructions)[1] == 'b')
				push_num(a, b, size_a, &size_b);
			else
			{
				write(2, "Error\n", 6);
				return (-1);
			}
		}
		else
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		*a = ft_first(*a);
		if (size_b > 0)
			*b = ft_first(*b);
		instructions++;
	}
	if (b)
		free(b);
	ft_printf("size_b = %d\n", size_b);
	return (size_b);
}

// This funtion applies all instructions and then check is the stack 'a' sorted
void	checker(char **instructions, t_stack **a, int *size_a)
{
	int	size_b;
	int	temp_size_a;

	size_b = 0;
	if (*size_a == 1 && !instructions)
	{
		ft_printf("OK\n");
		return ;
	}
	temp_size_a = *size_a;
	if (instructions)
		size_b = read_instructions(instructions, a, size_a);
	if (size_b == -1)
		return ;
	if (is_ordered(*a) && temp_size_a == *size_a && size_b == 0)
	{
		ft_printf("OK\n");
		return ;
	}
	ft_printf("KO\n");
}
