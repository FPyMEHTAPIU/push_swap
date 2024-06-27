/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:05:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/27 15:46:44 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_stack *arr, int size)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;
	int		j;

	temp1 = arr;
	i = 0;
	while (temp1->last != 1 && i < size)
	{
		j = 0;
		temp2 = arr;
		while (j < i)
		{
			//ft_printf("i = %d, arr[i] = %d\nj = %d, arr[j] = %d\n\n", i, arr[i], j, arr[j]);
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
int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (i == 0 && str[i] == '-')))
			return (0);
		i++;
	}
	return (1);
}

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

static int	check_range(t_stack *arr, int size, char **argv)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = arr;
	while (i < size && temp->last != 1)
	{
		//ft_printf("i = %d, arr[i] = %d, argv[i]: %s\n", i, arr[i], argv[i]);
		if ((temp->value == -1 && ft_strncmp(argv[size - 1 - i], "-1", 2) != 0))
			return (1);
		if ((temp->value == 0 && ft_strncmp(argv[size - 1 - i], "0", 1) != 0))
			return (1);
		i++;
		temp = temp->next;
	}
	return (0);
}

int	check_args(t_stack *arr, int size, char **argv)
{
	int	range;
	int	strs;
	int	doubles;

	if (size == 1)
		return (1);
	strs = check_strs(argv, size);
	//ft_printf("strs: %d\n", strs);
	if (strs)
		return (1);
	range = check_range(arr, size, argv);
	//ft_printf("range: %d\n", range);
	if (range)
		return (1);
	doubles = check_doubles(arr, size);
	//ft_printf("doubles: %d\n", doubles);
	if (doubles)
		return (1);
	return (0);
}
