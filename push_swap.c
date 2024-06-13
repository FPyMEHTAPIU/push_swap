/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/13 11:28:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*a;
	int	size;
	int	i;

	if (argc == 1)
		return (1);
	size = 0;
	a = convert_args(&argv[1], &size);
	if (check_args(a, size, &argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	i = 0;
	while (i < size)
	{
		ft_printf("%d ", a[i]);
		i++;
	}
	ft_printf("\n");
	
	return (0);
}
