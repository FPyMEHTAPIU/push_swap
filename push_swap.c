/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/16 16:25:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	**strs;

	size_a = 0;
	size_b = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = &argv[1];
	a = convert_args(strs, &size_a);
	if (check_args(a, size_a, strs))
	{
		ft_putstr("Error\n");
		return (1);
	}
	b = NULL; //malloc(sizeof(int));
	/*if (!b)
	{
		ft_printf("Allocation memory for the stack b is failed!\n");
		free(a);
		return (1);
	}*/
	sorting(a, b, &size_a, &size_b);
	/*ft_printf("Stack a after sorting:\n");
	int i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");*/
	
	free(a);
	free(b);
	return (0);
}
