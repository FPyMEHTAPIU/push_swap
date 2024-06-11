/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/11 15:16:59 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*arr;
	int	size;
	int	i;

	if (argc == 1)
		return (1);
	size = 0;
	arr = convert_args(&argv[1], &size);
	if (check_args(arr, size, &argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	i = 0;
	while (i < size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
	
	return (0);
}
