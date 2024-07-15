/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:59:02 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:30:22 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function returns first element in stack
t_stack	*ft_first(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->first != 1)
		lst = lst->prev;
	return (lst);
}
