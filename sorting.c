/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/20 16:25:23 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_check(int *a, int *b, int size_a, int size_b)
{
	int	i;
	int	j;
	int	rot_a;
	int	rot_b;

	i = size_a - 1;
	j = size_b - 1;
	rot_a = 0;
	rot_b = 0;
	if (i > 0 && a[i] > a[0] && a[0] <= a[i - 1])
		rot_a = 1;
	else if (i > 0 && a[i] > a[0] && a[i] > a[i - 1])
		rot_a = 2;
	if (j > 0 && b[j] < b[0] && b[0] >= b[j - 1])
		rot_b = 1;
	else if (j > 0 && b[j] < b[0] && b[j] < b[j - 1])
		rot_b = 2;
	if (rot_a == 0 && rot_b == 0)
		return (0);
	if (rot_a == rot_b && rot_a != 0)
	{
		if (rot_a == 1)
			return (5);
			//rotate_both(a, b, size_a, size_b);
		else if (rot_a == 2)
			return (6);
			//rrotate_both(a, b, size_a, size_b);
	}
	if (rot_a == 1)
		return (1);
		//rotate_one(a, size_a, 'a');
	else if (rot_a == 2)
		return (2);
		//rrotate_one(a, size_a, 'a');
	if (rot_b == 1)
		return (3);
		//rotate_one(b, size_b, 'b');
	else /*if (rot_b == 2)*/
		return (4);
		//rrotate_one(b, size_b, 'b');
}

static int	swap_check(int *a, int *b, int size_a, int size_b)
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
		return (0);
	else if (swap_a == 1 && swap_b == 1)
		return (3);
	else if (swap_a == 1)
		return (1);
	else /*if (swap_b == 1)*/
		return (2);
}

static void	checker(int *a, int *b, int size_a, int size_b)
{
	int rotate;
	int	swap;

	rotate = rotate_check(a, b, size_a, size_b);
	swap = swap_check(a, b, size_a, size_b);
	if (swap > 0 && (swap == 3 || rotate < 5))
	{
		if (swap == 1)
			swap_one(a, size_a, 'a');
		else if (swap == 2)
			swap_one(b, size_b, 'b');
		else if (swap == 3)
			swap_both(a, b, size_a, size_b);
	}
	else
	{
		if (rotate == 1)
			rotate_one(a, size_a, 'a');
		else if (rotate == 2)
			rrotate_one(a, size_a, 'a');
		else if (rotate == 3)
			rotate_one(b, size_b, 'b');
		else if (rotate == 4)
			rrotate_one(b, size_b, 'b');
		else if (rotate == 5)
			rotate_both(a, b, size_a, size_b);
		else if (rotate == 6)
			rrotate_both(a, b, size_a, size_b);
	}
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
		/*for (int s = 0; s < *size_a; s++)
		{
			ft_printf("a[%d] = %d\n", s, (*a)[s]);
		}*/
		// swap_check(*a, *b, *size_a, *size_b);
		// rotate_check(*a, *b, *size_a, *size_b);
		checker(*a, *b, *size_a, *size_b);
		checker(*a, *b, *size_a, *size_b);
		i = 0;
		while (i < *size_a - 1)
		{
			if ((*a)[i] > (*a)[i + 1])
				ordered_elems++;
			i++;
		}
		/*for (int s = 0; s < *size_a; s++)
		{
			ft_printf("a[%d] = %d\n", s, (*a)[s]);
		}*/
		if (ordered_elems == (*size_a) - 1)
		{
			if (*size_b == 0)
				return ;
			if ((*size_b) > 0)
			{
				push_num(b, a, size_b, size_a);
				ft_printf("pa\n");
				swap_check(*a, *b, *size_a, *size_b);
			}
		}
		else
		{
			if ((*size_a) > 0)
			{
				push_num(a, b, size_a, size_b);
				ft_printf("pb\n");
			}
		}
		ordered_elems = 0;
	}	
}
