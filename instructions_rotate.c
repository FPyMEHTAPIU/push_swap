/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:33 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/17 12:47:27 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_one(int *stack, const int size, char c)
{
	int	i;
	int	arr[size];

	i = 1;
	while (i < size)
	{
		arr[i - 1] = stack[i];
		i++;
	}
	arr[--i] = stack[0];
	i = 0;
	while (i < size)
	{
		stack[i] = arr[i];
		i++;
	}
	if (c != 0)
		ft_printf("r%c\n", c);
}

void	rotate_both(int *a, int *b, int size_a, int size_b)
{
	rotate_one(a, size_a, 0);
	rotate_one(b, size_b, 0);
	ft_printf("rr\n");
}

void	rrotate_one(int *stack, const int size, char c)
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
	if (c != 0)
		ft_printf("rr%c\n", c);
}

void	rrotate_both(int *a, int *b, int size_a, int size_b)
{
	rrotate_one(a, size_a, 0);
	rrotate_one(b, size_b, 0);
	ft_printf("rrr\n");
}
