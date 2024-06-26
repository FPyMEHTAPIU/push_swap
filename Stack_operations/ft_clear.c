/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:01:44 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/26 13:21:58 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//This function deletes only one passed node from the stack
void	ft_delone(t_list *stack)
{
	if (!stack)
		return ;
	free(stack);
}
//This fuction deletes all nodes from the stack and frees it
void	ft_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(stack);
}