/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:33:16 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:30:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function returns last element in stack
t_stack	*ft_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->last != 1)
		lst = lst->next;
	return (lst);
}
