/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 11:49:57 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (size_a == 1)
		return (free_and_ret(strs, a, size_a, 2));
	sorting(a, &size_a);
	return (free_and_ret(strs, a, size_a, 2));
}
