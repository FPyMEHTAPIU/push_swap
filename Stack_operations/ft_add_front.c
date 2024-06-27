/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:41:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 14:32:11 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This fuction adds the node to the start of the stack
It should be used with ft_stack_new(value) */
void	ft_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	(*stack)->first = 0;
	new->next = *stack;
	*stack = new;
	(*stack)->first = 1;
	(*stack)->next->next = ft_first(*stack);
	(*stack)->next->prev = *stack;
}
