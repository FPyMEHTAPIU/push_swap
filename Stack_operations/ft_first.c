/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:59:02 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 13:59:30 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_first(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->first != 1)
		lst = lst->next;
	return (lst);
}