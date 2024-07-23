/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:01:44 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/22 18:17:44 by msavelie         ###   ########.fr       */
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
		stack = NULL;
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

	if (!stack)
		return ;
	//*stack = ft_last(*stack);
	while (size/* - 1*/ > 0)
	{
		*stack = ft_last(*stack);
		temp = (*stack)->prev;
		ft_delone(*stack, size);
		*stack = temp;
		size--;
	}
	*stack = NULL;
	//free(*stack);
	free(stack);
	stack = NULL;
}
