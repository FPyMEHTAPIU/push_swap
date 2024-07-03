/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:47:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/03 15:47:12 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_one(t_stack *stack, int size, char c)
{
	t_stack	*temp;
	t_stack *s_last;
	t_stack *s_prev;

	if (size <= 1)
		return ;
	s_last = ft_last(stack);
	s_prev = s_last->prev;
	s_last->last = 0;
	s_prev->last = 1;
	if (size == 2)
	{
		stack->last = 1;
		s_last->last = 0;
	}
	temp = s_prev->prev;
	s_last->next = s_prev;
	s_last->prev = temp;
	s_prev->next = stack;
	s_prev->prev = s_last;
	temp->next = s_last;
	stack->prev = s_prev;
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
	ft_add_back(s2, ft_stack_new(ft_last(*s1)->value));
	(*size_s2)++;
	ft_delone(ft_last(*s1));
	(*size_s1)--;
}

