/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/30 17:28:48 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This fuction adds the node to the end of the stack
It should be used with ft_stack_new(value) */
t_stack	*ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return (*lst);
	if (!(*lst))
	{
		*lst = new;
		(*lst)->first = 1;
		(*lst)->last = 1;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
		return (*lst);
	}
	temp = *lst;
	while (temp->last != 1)
		temp = temp->next;
	temp->last = 0;
	new->prev = temp;
	new->last = 1;
	new->next = *lst;
	(*lst)->prev = new;
	temp->next = new;
	return (*lst);
}
