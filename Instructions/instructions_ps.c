/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:47:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/26 15:40:01 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_one(int *stack, int size, char c)
{
	int i;
	int temp;

	i = 0;
	if (size <= 1)
		return ;
	while (i < size)
		i++;
	temp = stack[i - 1];
	stack[i - 1] = stack[i - 2];
	stack[i - 2] = temp;
	if (c != 0)
		ft_printf("s%c\n", c);
}

void	swap_both(int *a, int *b, int size_a, int size_b)
{
	swap_one(a, size_a, 0);
	swap_one(b, size_b, 0);
	ft_printf("ss\n");
}
// num is provided outside from the top of another stack
/*static int	*copy_stack(int *stack, int size)
{
	int	*new_stack;
	int	i;

	if (size == 0)
	{
		free(stack);
		return (NULL);
	}	
	new_stack = malloc(sizeof(int) * size);
	if (!new_stack)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (i < size && stack)
	{
		new_stack[i] = stack[i];
		i++;
	}
	free(stack);
	return (new_stack);
}*/
/* Move top element from s1 to s2
s1 always decreases and s2 always increases (sizes change as well)
s1 and s2 can both be a and b */


//TODO
	// Create a function, that finds the last element in stack and points to it
	// Add last elem from s1 to the back of the s2
void	push_num(t_stack **s1, t_stack **s2, int *size_s1, int *size_s2)
{
	if (*size_s1 == 0)
		return ;
	/**s2 = copy_stack(*s2, ++(*size_s2));
	if (!s2)
	{
		free(s1);
		ft_fprintf(2, "Error\n");
		return ;
	}*/
	(*s2)[(*size_s2) - 1] = (*s1)[--(*size_s1)];
	*s1 = copy_stack(*s1, (*size_s1));
	if (!s1)
	{
		free(s2);
		ft_fprintf(2, "Error\n");
		return ;
	}
}

