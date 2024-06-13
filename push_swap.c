/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/13 13:11:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	i;

	if (argc == 1)
		return (0);
	size_a = 0;
	size_b = 0;
	a = convert_args(&argv[1], &size_a);
	if (check_args(a, size_a, &argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	b = malloc(sizeof(int));
	if (!b)
	{
		ft_printf("Allocation memory for the stack b is failed!\n");
		free(a);
		return (1);
	}

	ft_printf("Stack a before pushes:\n");
	i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("Stack b before pushes:\n");
	i = 0;
	while (i < size_b)
	{
		ft_printf("b[%d] = %d\n", i, b[i]);
		i++;
	}
	ft_printf("\n");

	// do some pushes (pa, pa, pb)
	ft_printf("size_a = %d, size_b = %d\n", size_a, size_b);
	push_num(a, b, &size_a, &size_b);
	ft_printf("size_a = %d, size_b = %d\n", size_a, size_b);
	push_num(a, b, &size_a, &size_b);
	ft_printf("size_a = %d, size_b = %d\n", size_a, size_b);
	push_num(b, a, &size_b, &size_a);
	ft_printf("size_a = %d, size_b = %d\n", size_a, size_b);

	ft_printf("Stack a after pushes:\n");
	i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("Stack b after pushes:\n");
	i = 0;
	while (i < size_b)
	{
		ft_printf("b[%d] = %d\n", i, b[i]);
		i++;
	}
	ft_printf("\n");
	
	return (0);
}
