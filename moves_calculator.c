/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:10:39 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/24 17:21:33 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//TODO:
	//Create a copy array for calculations (without allocation)
static int	compare_num_with_stack(int num, int *b, int size_b)
{
	int	j;
	int	max;
	int	index;

	j = size_b - 1;
	max = b[j];
	while (j >= 0)
	{
		if (max < b[j] && b[j] < num)
		{
			max = b[j];
			index = j;
		}
		j--;
	}
	j = 1;
	while (max != b[size_b - 1])
	{
		if (index > (size_b - 1) / 2)
			rotate_one(b, size_b, 'b');
		else
			rrotate_one(b, size_b, 'b');
		j++;
	}
	return (j);
}

int	calculator(int *a, int *b, int size_a, int size_b)
{
	int	indexes[size_a];
	int	i;

	i = size_a - 1;
	while (i >= 0)
	{
		// compare elements from 'a' to the second stack
		indexes[i] = compare_num_with_stack(a[i], b, size_b);
		i--;
	}
}