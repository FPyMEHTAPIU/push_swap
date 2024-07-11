/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:47:26 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/11 12:47:11 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**convert_args(char **argv, int *size_a)
{
	t_stack	**a;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	a = (t_stack**)malloc(sizeof(t_stack*) * i);
	if (!a)
		return (0);
	*a = NULL;
	*size_a = i;
	i = 0;
	while (i < *size_a)
	{
		if (!is_arg_number(argv[*size_a - 1 - i]))
			ft_add_back(a, ft_stack_new(-1));
		else
			ft_add_back(a, ft_stack_new(ft_atoi(argv[*size_a - 1 - i])));
		i++;
	}
	return (a);
}
