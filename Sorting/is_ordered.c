/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:01:37 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/07 12:05:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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