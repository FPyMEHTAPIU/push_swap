/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:47:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/16 16:28:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_one(int *stack, int size)
{
	int i;
	int temp;

	i = 0;
	if (size <= 1)
		return ;
	while (i < size)
		i++;
	temp = stack[i - 1];
	stack[i - 1] = stack[i - 2];
	stack[i - 2] = temp;
}

void	swap_both(int *a, int *b, int size_a, int size_b)
{
	swap_one(a, size_a);
	swap_one(b, size_b);
}
// num is provided outside from the top of another stack
static int	*copy_stack(int *stack, int size)
{
	int	*new_stack;
	int	i;

	ft_printf("size = %d\n", size);
	if (size == 0)
	{
		free(stack);
		return (NULL);
	}	
	new_stack = malloc(sizeof(int) * size);
	if (!new_stack)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (i < size && stack)
	{
		new_stack[i] = stack[i];
		ft_printf("stack[%d] = %d\n", i, stack[i]);
		ft_printf("new_stack[%d] = %d\n", i, new_stack[i]);
		i++;
	}
	//ft_printf("\n");
	//free(stack);
	return (new_stack);
}
/* Move top element from s1 to s2
s1 always decreases and s2 always increases (sizes change as well)
s1 and s2 can both be a and b */
void	push_num(int **s1, int **s2, int *size_s1, int *size_s2)
{
	if (*size_s1 == 0)
		return ;
	ft_printf("\nCreating 2-d stack:\n");
	*s2 = copy_stack(*s2, ++(*size_s2));
	/*if (!s2)
	{
		free(s1);
		ft_printf("Error\n");
		return ;
	}*/
	/*ft_printf("new_s2[%d] = %d\ts1[%d] = %d\n", (*size_s2) - 1, s2[(*size_s2)-1], (*size_s1) - 1, s1[(*size_s1 ) - 1]);	
	ft_printf("Assigning the last element from the 1-st stack to the 2-nd\n");*/
	(*s2)[(*size_s2) - 1] = (*s1)[--(*size_s1)];
	//ft_printf("new_s2[%d] = %d\ts1[%d] = %d\n", (*size_s2) - 1, s2[(*size_s2)-1], (*size_s1), s1[(*size_s1)]);
	
	ft_printf("\nCreating 1-st stack:\n");
	*s1 = copy_stack(*s1, (*size_s1));
	/*if (!s1)
	{
		free(s2);
		ft_printf("Error\n");
		return ;
	}*/
}

