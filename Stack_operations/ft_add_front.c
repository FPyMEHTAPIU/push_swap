/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:41:29 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/28 13:42:50 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

////////////////// THE SECOND ELEMENT IS LOSING WTF?!

/* This fuction adds the node to the start of the stack
It should be used with ft_stack_new(value) */
void	ft_add_front(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	temp = new->prev;
	new->next = *stack;
	(*stack)->prev = new;
	(*stack)->first = 0;
	new->last = 0;
	new->first = 1;
	temp->last = 1;
	*stack = new;
	//(*stack)->next->next = ft_first(*stack);
	//(*stack)->prev = temp;
}
