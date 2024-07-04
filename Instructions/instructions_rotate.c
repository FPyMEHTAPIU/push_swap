/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:33 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/04 14:16:59 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate_one(t_stack *stack, /*const int size,*/ char c)
{
	t_stack	*temp;
	t_stack	*first;

	first = ft_first(stack);
	if (!first)
		return ;
	temp = ft_last(stack);
	temp->last = 0;
	first->last = 1;
	first->first = 0;
	first->next->first = 1;
	first->prev = temp;
	temp->next = first;
	/*first->next = stack->next;
	stack = first->next;*/
	
	if (c != 0)
		ft_printf("rr%c\n", c);
}

void	rrotate_both(t_stack *a, t_stack *b) //, int size_a, int size_b)
{
	rrotate_one(a, 0);
	rrotate_one(b, 0);
	ft_printf("rrr\n");
}

void	rotate_one(t_stack *stack, /*const int size,*/ char c)
{
	t_stack	*s_first;
	t_stack	*s_last;

	s_first = ft_first(stack);
	s_last = ft_last(stack);
	s_last->last = 0;
	s_last->first = 1;
	s_last->prev->last = 1;
	s_first->first = 0; 
	
	if (c != 0)
		ft_printf("r%c\n", c);
}

void	rotate_both(t_stack *a, t_stack *b) //, int size_a, int size_b)
{
	rotate_one(a, 0);
	rotate_one(b, 0);
	ft_printf("rr\n");
}
