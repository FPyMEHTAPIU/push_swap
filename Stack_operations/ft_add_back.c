/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/04 13:37:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This fuction adds the node to the end of the stack
It should be used with ft_stack_new(value) */
t_stack	*ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*s_last;
	t_stack	*s_first;

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
	s_last = ft_last(*lst);
	s_first = ft_first(*lst);
	s_last->last = 0;
	new->prev = s_last;
	new->last = 1;
	new->next = s_first;
	s_first->prev = new;
	s_last->next = new;
	return (s_first);
}
