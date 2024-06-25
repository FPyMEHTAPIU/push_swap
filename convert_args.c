/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:47:26 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/25 15:05:16 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*convert_args(char **argv)
{
	t_list	*a;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	a = malloc(sizeof(t_list) * i);
	if (!a)
		return (0);
	a->size = i;
	i = 0;
	while (i < a->size)
	{
		if (!is_arg_number(argv[a->size - 1 - i]))
			a->value = -1;
		else
			a->value = ft_atoi(argv[a->size - 1 - i]);
		i++;
		a = a->next;
	}
	a = a->next;
	return (a);
}
