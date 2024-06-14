/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/14 18:18:27 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* I CAN'T USE BUBBLE SORT BECAUSE IT IS FUCKING STACK :D
I CAN HANDLE WITH ONLY 2 LAST ELEMS OR 1ST AND LAST */
void sorting(int *a, int *b, int *size_a, int *size_b)
{
	int i;
	int ordered_elems;

	ordered_elems = 0;
	while (!ordered_elems)
	{
		i = *size_a - 1;
		if (a[i] > a[i - 1])
			swap_one(a, *size_a);
		i = 0;
		while (i < *size_a - 1)
		{
			ft_printf("Is a problem here?\n");
			ft_printf("a[%d] = %d > a[%d] = %d\n", i, a[i], i+1, a[i+1]);
			if (a[i] > a[i + 1])
			{
				ordered_elems++;
			}
				
			i++;
		}
		ft_printf("ordered_elems = %d\n", ordered_elems);
		ft_printf("size_a = %d\n", *size_a);
		if (ordered_elems == (*size_a) - 1)
		{
			while ((*size_b) > 0)
			{
				ft_printf("Doing push from b to a\n");
				push_num(b, a, size_b, size_a);
			}
			ordered_elems = 1;
		}
		else
		{
			ft_printf("Is anybody here?\n");
			ft_printf("size_b = %d\n", *size_b);
			if ((*size_a) > 0)
			{
				ft_printf("Doing push from a to b\n");
				push_num(a, b, size_a, size_b);
			}
			ordered_elems = 0;
		}
		ft_printf("size_a at the end = %d\n", *size_a);
		ft_printf("ordered_elems = %d\n", ordered_elems);
	}
}
