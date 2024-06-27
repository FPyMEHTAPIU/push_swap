/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:41:33 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 15:57:03 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate_one(t_stack *stack, /*const int size,*/ char c)
{
	ft_add_back(&stack, ft_first(stack));
	ft_delone(ft_first(stack));
	/*while (i < size)
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
	}*/
	if (c != 0)
		ft_printf("rr%c\n", c);
}

void	rrotate_both(t_stack *a, t_stack *b) //, int size_a, int size_b)
{
	rrotate_one(a, 0);
	rrotate_one(b, 0);
	ft_printf("rrr\n");
}

void	rotate_one(t_stack *stack, /*const int size,*/ char c)
{
	ft_add_front(&stack, ft_last(stack));
	ft_delone(ft_last(stack));
	/*int	i;
	int	arr[size];

	i = 0;
	while (i + 1 < size)
	{
		arr[i + 1] = stack[i];
		i++;
	}
	arr[0] = stack[i];
	i = 0;
	while (i < size)
	{
		stack[i] = arr[i];
		i++;
	}*/
	if (c != 0)
		ft_printf("r%c\n", c);
}

void	rotate_both(t_stack *a, t_stack *b) //, int size_a, int size_b)
{
	rotate_one(a, 0);
	rotate_one(b, 0);
	ft_printf("rr\n");
}
