/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:47:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/13 13:06:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_one(int *stack)
{
	int i;
	int temp;

	i = 0;
	while (stack[i])
		i++;
	temp = stack[i - 1];
	stack[i - 1] = stack[i - 2];
	stack[i - 2] = temp;
}

void	swap_both(int *a, int *b)
{
	swap_one(a);
	swap_one(b);
}
// num is provided outside from the top of another stack
int	*copy_stack(int *stack, int size)
{
	int	*new_stack;
	int	i;

	new_stack = malloc(sizeof(int) * size);
	if (!new_stack)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ft_printf("stack[%d] = %d\n", i, stack[i]);
		new_stack[i] = stack[i];
		i++;
	}
	free(stack);
	return (new_stack);
}
/* We chose the operation (pa or pb) outside (!!!!!SPECIFY!!!!!)
s1 always decreases and s2 always increases (sizes change as well)
s1 and s2 can both be a and b */
void	push_num(int *s1, int *s2, int *size_s1, int *size_s2)
{
	int	*new_s1;
	int	*new_s2;
	
	ft_printf("Creating 2-d stack:\n");
	new_s2 = copy_stack(s2, ++(*size_s2));
	if (!new_s2)
		return ;
	ft_printf("Assigning the last element from the 1-st stack to the 2-nd\n");
	ft_printf("new_s2[%d] = %d\ts1[%d] = %d\n", (*size_s2) - 1, new_s2[(*size_s2) - 1], (*size_s1) - 1, s1[(*size_s1)-1]);
	new_s2[(*size_s2) - 1] = s1[--(*size_s1)];
	
	ft_printf("Creating 1-st stack:\n");
	new_s1 = copy_stack(s1, (*size_s1));
	if (!new_s1)
		return ;
	s1 = new_s1;
	s2 = new_s2;
}

