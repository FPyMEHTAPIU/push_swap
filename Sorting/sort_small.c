/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:57:19 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/08 14:55:51 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small(t_stack *a, int size_a)
{
	t_stack	*last;

	a = ft_first(a);
	while (!is_ordered(a))
	{
		if (size_a == 3)
		{
			last = ft_last(a);
			//if (a[2] > a[1] && a[2] < a[0])
			if (last->value > a->next->value && last->value < a->value)
				swap_one(a, size_a, 'a');
			//else if (a[0] < a[1] && a[0] > a[2])
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
