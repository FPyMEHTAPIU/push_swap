/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:47:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/30 18:55:18 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_one(t_stack *stack, int size, char c)
{
	t_stack *temp_last;
	t_stack *temp_prev;

	if (size <= 1)
		return ;
	temp_last = stack;
	temp_prev = stack->prev;
	stack->first = 0;
	temp_prev->first = 1;
	if (size == 2)
	{
		stack->last = 1;
		temp_prev->last = 0;
	}
	stack = temp_prev;
	stack->prev = temp_last;
	stack->next = ft_first(stack);
	stack->prev->next = stack;
	if (c != 0)
		ft_printf("s%c\n", c);
}

void	swap_both(t_stack *a, t_stack *b, int size_a, int size_b)
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
	ft_add_back(s2, ft_last(*s1));
	(*size_s2)++;
	ft_delone(ft_last(*s1));
	(*size_s1)--;
}

