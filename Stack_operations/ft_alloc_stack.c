/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:58:54 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:32:31 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This function allocates memory for the stack 'b' 
and push one element from 'a' into 'b' */
t_stack	**alloc_stack(t_stack **a, int *size_a, int *size_b)
{
	t_stack	**b;

	b = (t_stack **)malloc(sizeof(t_stack *) * ((*size_a) - 3));
	if (!b)
		return (NULL);
	push_num(a, b, size_a, size_b);
	ft_printf("pb\n");
	return (b);
}
