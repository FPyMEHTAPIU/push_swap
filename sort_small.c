/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:57:19 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/24 15:58:28 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordered(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] < a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_small(int *a, int size_a)
{
	while (!is_ordered(a, size_a))
	{
		if (size_a == 3)
		{
			if (a[2] > a[1] && a[2] < a[0])
				swap_one(a, size_a, 'a');
			else if (a[0] < a[1] && a[0] > a[2])
				rrotate_one(a, size_a, 'a');
			else
				rotate_one(a, size_a, 'a');
		}
		else
			swap_one(a, size_a, 'a');
	}
}