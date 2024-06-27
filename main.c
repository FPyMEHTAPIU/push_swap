/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 17:29:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	**a;
	t_stack	**b;
	int		size_a;
	int		size_b;
	char	**strs;

	size_a = 0;
	size_b = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = &argv[1];
	a = convert_args(strs, &size_a);
	if (check_args(*a, size_a, strs) || size_a == 0)
	{
		if (argc == 2)
			free(strs);
		free(a);
		ft_fprintf(2, "Error\n");
		//write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		free(strs);
	if (size_a == 1)
	{
		free(a);
		return (0);
	}
	b = NULL;
	/*ft_printf("Stack a before sorting:\n");
	int i = size_a - 1;
	while (i >= 0)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i--;
	}
	ft_printf("\n");*/
	sorting(a, b, &size_a, &size_b);
	/*ft_printf("Stack a after sorting:\n");
	i = size_a - 1;
	while (i >= 0)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i--;
	}
	ft_printf("\n");*/
	ft_clear(a);
	ft_clear(b);
	return (0);
}
