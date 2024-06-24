/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/24 15:42:05 by msavelie         ###   ########.fr       */
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

static void	sort_small(int *a, int size_a)
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

void sorting(int **a, int **b, int *size_a, int *size_b)
{
	if (*size_a <= 3)
	{
		sort_small(*a, *size_a);
		return ;
	}
	b = malloc(sizeof(int) * 2);
	if (!b)
	{
		free(a);
		return ;
	}
	*size_b += 2;
}