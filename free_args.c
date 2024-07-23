/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:41:09 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 11:54:42 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function frees memory allocated in ft_split
int	free_strs(char **list, int index)
{
	if (!list)
		return (1);
	while (index >= 0)
	{
		free(list[index]);
		list[index] = NULL;
		index--;
	}
	free(list);
	list = NULL;
	return (1);
}

/*---
TYPE VALUES: 
1 - free strs
2 - free stack and return
3 - free all without error
4 - free strs and print error
5 - free stack and print error
6 - free all and print error
---*/
int	free_and_ret(char **strs, t_stack **stack, int size_a, int type)
{
	if (type != 2 && type != 5)
		free_strs(strs, size_a);
	if (type > 3)
		write(2, "Error\n", 6);
	if (type == 2 || type == 3 || type == 5 || type == 6)
		if (size_a > 0)
			ft_clear(stack, size_a);
	return (0);
}
