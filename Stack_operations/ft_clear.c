/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:01:44 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/11 15:02:42 by msavelie         ###   ########.fr       */
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
void	ft_clear(t_stack **stack, int size)
{
	t_stack	*temp;

	*stack = ft_last(*stack);
	if (!stack)
		return ;
	while (size - 1 > 0 /*(*stack)->first != 1*/)
	{
		temp = (*stack)->prev;
		ft_delone(*stack, size);
		/*free(*stack);
		*stack = NULL;*/
		*stack = temp;
		size--;
	}
	//free(*stack);
	free(stack);
}
