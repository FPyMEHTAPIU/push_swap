/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:09:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/26 13:35:53 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	**alloc_stack(t_stack **a, int *size_a, int *size_b)
{
	t_stack	**b;
	int		i;

	b = malloc(sizeof(t_stack) * 2);
	if (!b)
		return (NULL);
	*size_b += 2;
	i = 0;
	while (i++ < 2)
	{
		push_num(a, b, size_a, size_b);
		ft_printf("pb\n");
	}
	return (b);
}

void sorting(int **a, int **b, int *size_a, int *size_b)
{
	if (*size_a <= 3)
	{
		sort_small(*a, *size_a);
		return ;
	}
	if (!alloc_stack(a, b, size_a, size_b))
		return ;
	while (*size_a > 3)
	{
		
	}
}