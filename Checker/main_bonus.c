/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/16 16:43:01 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// This function frees memory allocated in ft_split
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

/*---
TYPE VALUES: 
1 - free strs
2 - free stack and return
3 - free all without error
4 - free strs and print error
5 - free stack and print error
6 - free all and print error
---*/
static int	free_and_ret(char **strs, t_stack **stack, int size_a, int type)
{
	if (type != 2 && type != 5)
		free_strs(strs, size_a);
	if (type > 3)
		write(2, "Error\n", 6);
	if (type == 2 || type == 3 || type == 5 || type == 6)
		ft_clear(stack, size_a);
	return (0);
}

// This function frees all allocated if they exist and print error
static int	invalid_input(int argc, char **strs, int size_a, t_stack **a)
{
	if (argc == 2)
		free_strs(strs, size_a);
	return (free_and_ret(strs, a, size_a, 5));
}

int	main(int argc, char *argv[])
{
	t_stack	**a;
	int		size_a;
	char	**strs;
	char	*arguments;
	//int		fd;

	size_a = 0;
	a = NULL;
	if (argc < 2)
		return (0);
	int i = 1;
	while (argv[i])
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	arguments = get_next_line(0);
	while (arguments != NULL)
	{	
		if (!arguments)
			return (0);
		ft_printf(arguments);
		arguments = get_next_line(0);
	}
	strs = ft_split(argv[1], ' '); // replace argv[1] to arguments
	if (!strs || !(*strs))
		return (free_and_ret(strs, a, size_a, 4));
	else
		strs = &argv[1];
	a = convert_args(strs, &size_a);
	if (check_args(*a, size_a, strs) || size_a == 0)
		return (invalid_input(argc, strs, size_a, a));
	if (argc == 2)
		free_strs(strs, size_a);
	if (size_a == 1)
		return (free_and_ret(strs, a, size_a, 2));
	sorting(a, &size_a);// replace for the checker
	return (free_and_ret(strs, a, size_a, 2));
}
