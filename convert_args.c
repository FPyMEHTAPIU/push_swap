/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:47:26 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/11 14:04:47 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_args(char **argv, int *size)
{
	int	*arr;
	int	i;

	size = 0;
	while (argv[*size])
		(*size)++;
	ft_printf("size: %d\n", *size);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (0);
	i = 0;
	while (i < *size)
	{
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}