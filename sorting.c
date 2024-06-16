/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/16 12:27:09 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_check(int *a, int *b, int size_a, int size_b)
{
	int	i;
	int	j;
	int	rot_a;
	int	rot_b;

	i = size_a - 1;
	j = size_b - 1;
	rot_a = 0;
	rot_b = 0;
	if (a[i] > a[0] && a[0] <= a[i - 1])
		rot_a = 1;
	else if(a[i] > a[0] && a[i] > a[i - 1])
		rot_a = 2;
	if (b[j] < b[0] && b[0] >= b[j - 1])
		rot_b = 1;
	else if(b[j] < b[0] && b[j] < b[j - 1])
		rot_b = 2;
	if (rot_a == 0 && rot_b == 0)
		return ;
	if (rot_a == rot_b && rot_a != 0)
	{
		if (rot_a == 1)
			rotate_both(a, b, size_a, size_b);
		else if (rot_a == 2)
			rrotate_both(a, b, size_a, size_b);
		return ;
	}
	if (rot_a == 1)
	{
		rotate_one(a, size_a, 'a');
		/*ft_printf("rot_a = %d\trot_b = %d\n", rot_a, rot_b);
		for(int w = 0; w < 2; w++)
			ft_printf("b[%d] = %d\n", w, b[w]);*/
	}
		
	else if (rot_a == 2)
		rrotate_one(a, size_a, 'a');
	if (rot_b == 1)
		rotate_one(b, size_b, 'b');
	else if (rot_b == 2)
		rrotate_one(b, size_b, 'b');
}

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
		{
			swap_one(a, *size_a);
			ft_printf("sa\n");
		}
		rotate_check(a, b, *size_a, *size_b);
		i = 0;
		while (i < *size_a - 1)
		{
			if (a[i] > a[i + 1])
				ordered_elems++;
			i++;
		}
		if (ordered_elems == (*size_a) - 1)
		{
			while ((*size_b) > 0)
			{
				push_num(b, a, size_b, size_a);
				ft_printf("pa\n");
			}
			ordered_elems = 1;
		}
		else
		{
			if ((*size_a) > 0)
			{
				push_num(a, b, size_a, size_b);
				ft_printf("pb\n");
			}
			ordered_elems = 0;
		}
	}
}
