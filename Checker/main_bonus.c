/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/19 16:28:03 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// This function frees memory allocated in ft_split
static int	free_strs(char **list, int index)
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

					/////////////////////////NEW PART///////////////////////////////////
static char	**realloc_arr(char **arr, int *size, int lines)
{
	char	**new_arr;
	int		i;

	i = 0;
	new_arr = ft_calloc((*size * 2), sizeof(char *));
	if (!new_arr)
	{
		free_strs(arr, *size);
		return (NULL);
	}
	while (i < lines)
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr)
		{
			free_strs(new_arr, i);
			free_strs(arr, lines);
		}
		i++;
	}
	free_strs(arr, lines);
	*size *= 2;
	return (new_arr);
}

static char	**get_instructions(void)
{
	char	**instr_arr;
	char	*buf;
	int		lines;
	int		size;

	lines = 0;
	size = INSTR_SIZE;
	instr_arr = ft_calloc((size + 1), sizeof(char *));
	if (!instr_arr)
		return (NULL);
	buf = get_next_line(0);
	while (buf)
	{
		instr_arr[lines] = ft_strdup(buf);
		lines++;
		if (lines == size)
			instr_arr = realloc_arr(instr_arr, &size, lines);
		free(buf);
		buf = get_next_line(0);
	}
	ft_printf("lines = %d\n", lines);
	if (lines == 0)
	{
		free_strs(instr_arr, lines);
		return (NULL);
	}	
	return (instr_arr);
}

int	main(int argc, char *argv[])
{
	t_stack	**a;
	int		size_a;
	char	**instr_arr;
	char	**strs;
	int		lines;

	size_a = 0;
	a = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{			
		strs = ft_split(argv[1], ' ');
		if (!strs || !(*strs))
			return (free_and_ret(strs, a, size_a, 4));
	}
	else
		strs = &argv[1];
	a = convert_args(strs, &size_a);
	if (check_args(*a, size_a, strs) || size_a == 0)
		return (invalid_input(argc, strs, size_a, a));
	if (argc == 2)
		free_strs(strs, size_a);
	instr_arr = get_instructions();
	lines = 0;
	if (!check_instructions(instr_arr, &lines))
		write(2, "Error\n", 6);
	else
		checker(instr_arr, a, &size_a);
	free_strs(instr_arr, lines);
	if (size_a == 1)
		return (free_and_ret(strs, a, size_a, 2));
	return (free_and_ret(strs, a, size_a, 2));
}
