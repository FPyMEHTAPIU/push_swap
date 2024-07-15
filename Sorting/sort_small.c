/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:57:19 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:17:07 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// This function sorts stack 'a' if there are only 3 numbers
void	sort_small(t_stack *a, int size_a)
{
	t_stack	*last;

	a = ft_first(a);
	while (!is_ordered(a))
	{
		if (size_a == 3)
		{
			last = ft_last(a);
			if (last->value > a->next->value && last->value < a->value)
				swap_one(a, size_a, 'a');
			else if (a->value < a->next->value && a->next->value > last->value)
				rrotate_one(a, 'a');
			else
				rotate_one(a, 'a');
		}
		else
			swap_one(a, size_a, 'a');
		a = ft_first(a);
	}
}
