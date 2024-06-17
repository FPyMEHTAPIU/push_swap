/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/17 16:53:15 by msavelie         ###   ########.fr       */
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
	/*ft_printf("b = %p\n", b);
	for (int q = 0; q < size_a; q++)
	{
		ft_printf("a[%d] = %d ", q, a[q]);
		ft_printf("\n");
	}
	for (int q = 0; q < size_b; q++)
	{
		ft_printf("b[%d] = %d ", q, b[q]);
		ft_printf("\n");
	}*/
	if (i > 0 && a[i] > a[0] && a[0] <= a[i - 1])
		rot_a = 1;
	else if(i > 0 && a[i] > a[0] && a[i] > a[i - 1])
		rot_a = 2;
	/*if (j > 0)
		ft_printf("j = %d, b[%d] = %d, b[0] = %d, b[%d] = %d\n", j, j, b[j], b[0], j-1, b[j-1]);*/
	if (j > 0 && b[j] < b[0] && b[0] >= b[j - 1])
		rot_b = 1;
	else if(j > 0 && b[j] < b[0] && b[j] < b[j - 1])
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
		//ft_printf("size_a = %d\tsize_b = %d\n", size_a, size_b);
		rotate_one(a, size_a, 'a');
		//ft_printf("rot_a = %d\trot_b = %d\n", rot_a, rot_b);
	}
	else if (rot_a == 2)
		rrotate_one(a, size_a, 'a');
	if (rot_b == 1)
		rotate_one(b, size_b, 'b');
	else if (rot_b == 2)
		rrotate_one(b, size_b, 'b');
	/*for(int w = 0; w < 2; w++)
		ft_printf("b[%d] = %d\n", w, b[w]);*/
}

void	swap_check(int *a, int *b, int size_a, int size_b)
{
	int	i;
	int	swap_a;
	int	swap_b;

	i = size_a - 1;
	swap_a = 0;
	swap_b = 0;
	if (size_a > 1 && a[i] > a[i - 1])
		swap_a = 1;
	i = size_b - 1;
	if (size_b > 1 && b[i] < b[i - 1])
		swap_b = 1;
	if (swap_a == swap_b && swap_a == 0)
		return ;
	else if (swap_a == 1 && swap_b == 1)
		swap_both(a, b, size_a, size_b);
	else if (swap_a == 1)
		swap_one(a, size_a, 'a');
	else if (swap_b == 1)
		swap_one(b, size_b, 'b');
}

/* I CAN'T USE BUBBLE SORT BECAUSE IT IS FUCKING STACK :D
I CAN HANDLE WITH ONLY 2 LAST ELEMS OR 1ST AND LAST */
void sorting(int **a, int **b, int *size_a, int *size_b)
{
	int i;
	int ordered_elems;

	ordered_elems = 0;
	while (!ordered_elems)
	{
		i = *size_a - 1;
		if ((*a)[i] > (*a)[i - 1])
			swap_one(*a, *size_a, 'a');
		rotate_check(*a, *b, *size_a, *size_b);
		i = 0;
		while (i < *size_a - 1)
		{
			if ((*a)[i] > (*a)[i + 1])
				ordered_elems++;
			i++;
		}
		if (ordered_elems == (*size_a) - 1)
		{
			if (*size_b == 0)
				return ;
			while ((*size_b) > 0)
			{
				push_num(b, a, size_b, size_a);
				ft_printf("pa\n");
				swap_check(*a, *b, *size_a, *size_b);
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
