/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 11:52:46 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// This function copies data, frees old memory and allocates x2 memory for the object
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

static char	**get_instructions(int *lines)
{
	char	**instr_arr;
	char	*buf;
	int		size;

	size = INSTR_SIZE;
	instr_arr = ft_calloc((size + 1), sizeof(char *));
	if (!instr_arr)
		return (NULL);
	buf = get_next_line(0);
	while (buf)
	{
		instr_arr[*lines] = ft_strdup(buf);
		(*lines)++;
		if (*lines == size)
			instr_arr = realloc_arr(instr_arr, &size, *lines);
		free(buf);
		buf = get_next_line(0);
	}
	if (*lines == 0)
	{
		free_strs(instr_arr, *lines);
		return (NULL);
	}
	return (instr_arr);
}

static void	choose_checker(t_stack **a, int *size_a)
{
	char	**instr_arr;
	int		lines;

	lines = 0;
	instr_arr = get_instructions(&lines);
	if (!check_instructions(instr_arr, &lines))
		write(2, "Error\n", 6);
	else
		checker(instr_arr, a, size_a, lines);
	if (instr_arr && lines > 0)
		free_strs(instr_arr, lines);
}

int	main(int argc, char *argv[])
{
	t_stack	**a;
	int		size_a;
	char	**strs;

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
	choose_checker(a, &size_a);
	if (size_a > 0)
		return (free_and_ret(strs, a, size_a, 2));
	return (0);
}
