/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/19 15:33:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;

	size_a = 0;
	size_b = 0;
	if (argc == 1)
		return (0);
	a = convert_args(&argv[1], &size_a);
	if (check_args(a, size_a, &argv[1]))
	{
		free(a);
		ft_fprintf(2, "Error\n");
		//write(2, "Error\n", 6);
		return (0);
	}
	b = NULL;
	ft_printf("Stack a before sorting:\n");
	int i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");
	sorting(&a, &b, &size_a, &size_b);
	ft_printf("Stack a after sorting:\n");
	i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");

	free(a);
	free(b);
	return (0);
}
