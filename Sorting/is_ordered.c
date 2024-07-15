/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:01:37 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:16:12 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function checks is the stack 'a' ordered
int	is_ordered(t_stack *s)
{
	while (s->next->first != 1)
	{
		if (s->value < s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

// This function checks is the stack 'b' ordered
int	is_ordered_b(t_stack *s)
{
	while (s->next->first != 1)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}
