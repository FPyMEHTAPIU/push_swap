/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/14 13:35:34 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_strs(char **list, int index)
{
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
/*TYPE VALUES: 
1 - free strs
2 - free stack and return
3 - free all without error
4 - free strs and print error 
5 - free all and print error */
/*static int	free_and_ret(char **strs, t_stack **stack, int size_a, int type)
{
	if (type != 2)
		free_strs(strs, size_a);
	if (type > 3)
		write(2, "Error\n", 6);
	if (type == 2 || type == 3 || type == 5)
		ft_clear(stack, size_a);
	return (0);
}*/

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
	{			
		strs = ft_split(argv[1], ' ');
		if (!strs || !(*strs))
		{
			write(2, "Error\n", 6);
			free_strs(strs, size_a);
			return (0);
		}
	}
	else
		strs = &argv[1];
	a = convert_args(strs, &size_a);
	if (check_args(*a, size_a, strs) || size_a == 0)
	{
		if (argc == 2)
			free_strs(strs, size_a);
		ft_clear(a, size_a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		free_strs(strs, size_a);
	if (size_a == 1)
	{
		ft_clear(a, size_a);
		return (0);
	}
	b = NULL;
	sorting(a, b, &size_a, &size_b);
	ft_clear(a, size_a);
	return (0);
}
