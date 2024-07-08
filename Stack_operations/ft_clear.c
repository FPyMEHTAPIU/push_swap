/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:01:44 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/08 14:48:22 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//This function deletes only one passed node from the stack
void	ft_delone(t_stack *stack, int size)
{
	t_stack	*first;

	if (!stack)
		return ;
	if (size == 1)
	{
		free(stack);
		return ;
	}
	first = ft_first(stack);
	stack->last = 0;
	stack->prev->last = 1;
	stack->prev->next = first;
	first->prev = stack->prev;
	free(stack);
	stack = first;
}
//This fuction deletes all nodes from the stack and frees it
void	ft_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while ((*stack)->last != 1)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(stack);
}