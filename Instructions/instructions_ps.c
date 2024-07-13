/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:47:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/13 14:15:04 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	change_ptrs(t_stack *stack, t_stack *s_last, t_stack *s_prev)
{
	t_stack	*temp;

	temp = s_prev->prev;
	s_last->next = s_prev;
	s_last->prev = temp;
	s_prev->next = stack;
	s_prev->prev = s_last;
	temp->next = s_last;
	stack->prev = s_prev;
}

void    swap_one(t_stack *stack, int size, char c)
{
	
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
		s_prev->first = 0;
		s_last->first = 1;
	}
	else
		change_ptrs(stack, s_last, s_prev);
	if (c != 0)
		ft_printf("s%c\n", c);
}

void	swap_both(t_stack *a, t_stack *b, int size_a, int size_b)
{
	swap_one(a, size_a, 0);
	swap_one(b, size_b, 0);
	ft_printf("ss\n");
}

/* Move top element from s1 to s2
s1 always decreases and s2 always increases (sizes change as well)
s1 and s2 can both be a and b */
void	push_num(t_stack **s1, t_stack **s2, int *size_s1, int *size_s2)
{
	if (*size_s1 == 0)
		return ;
	ft_add_back(s2, ft_stack_new(ft_last(*s1)->value));
	(*size_s2)++;
	ft_delone(ft_last(*s1), *size_s1);
	if (*size_s1 == 1)
		free(s1);
	(*size_s1)--;
}

