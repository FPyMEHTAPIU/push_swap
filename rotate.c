/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:33 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/13 16:04:00 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_one(int *stack, int size)
{
	int	i;
	int	arr[size];

	i = 1;
	while (i < size)
	{
		arr[i - 1] = stack[i];
		i++;
	}
	arr[i] = stack[0];
	i = 0;
	while (i < size)
	{
		stack[i] = arr[i];
		i++;
	}
}

void	rotate_both(int *a, int *b, int size_a, int size_b)
{
	rotate_one(a, size_a);
	rotate_one(b, size_b);
}

void	rrotate_one(int *stack, int size)
{
	int	i;
	int	arr[size];

	i = 0;
	while (i + 1 < size)
	{
		arr[i] = stack[i + 1];
		i++;
	}
	arr[i] = stack[0];
	i = 0;
	while (i < size)
	{
		stack[i] = arr[i];
		i++;
	}
}

void	rrotate_both(int *a, int *b, int size_a, int size_b)
{
	rrotate_one(a, size_a);
	rrotate_one(b, size_b);
}
