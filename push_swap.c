/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/11 14:05:52 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*arr;
	int	size;

	if (argc == 1)
		return (1);
	size = 0;
	arr = convert_args(&argv[1], &size);
	if (check_args(arr, size))
		return (1);
	while (*arr)
	{
		ft_printf("%d ", *arr);
		arr++;
	}
	ft_printf("\n");
	
	return (0);
}