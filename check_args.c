/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:05:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/16 15:42:32 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function checks are there the same numbers
static int	check_doubles(t_stack *arr, int size)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;
	int		j;

	temp1 = arr;
	i = 0;
	while (i < size)
	{
		j = 0;
		temp2 = arr;
		while (j < i)
		{
			if (temp1->value == temp2->value)
				return (1);
			j++;
			temp2 = temp2->next;
		}
		i++;
		temp1 = temp1->next;
	}
	return (0);
}

/* This function compares each character in string 
and returns 0 if this is correct number */
int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (i == 0
			&& ((str[i] == '-') || str[i] == '+'))))
			return (0);
		i++;
	}
	return (1);
}

// This function checks are there only numbers
static int	check_strs(char **argv, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_arg_number(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

// This function cheks INT ranges
static int	check_range(t_stack *arr, int size, char **argv)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = arr;
	while (i < size)
	{
		if ((temp->value == -1 && ft_strncmp(argv[size - 1 - i], "-1", 2) != 0))
			return (1);
		if ((temp->value == 0 && ft_strncmp(argv[size - 1 - i], "-0", 2) == 0))
			return (0);
		if ((temp->value == 0 && ft_strncmp(argv[size - 1 - i], "+0", 2) == 0))
			return (0);
		if ((temp->value == 0 && ft_strncmp(argv[size - 1 - i], "0", 1) != 0))
			return (1);
		i++;
		temp = temp->next;
	}
	return (0);
}

// This function checks is our number valid. If number is valid it returns 0
int	check_args(t_stack *arr, int size, char **argv)
{
	int	range;
	int	strs;
	int	doubles;

	strs = check_strs(argv, size);
	if (strs)
		return (1);
	range = check_range(arr, size, argv);
	if (range)
		return (1);
	doubles = check_doubles(arr, size);
	if (doubles)
		return (1);
	return (0);
}
