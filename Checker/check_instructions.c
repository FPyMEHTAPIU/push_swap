/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:52:42 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 11:15:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_instructions(char **instr_arr, int *lines)
{
	int	i;

	i = 0;
	if (!instr_arr)
		return (1);
	while (instr_arr[*lines])
		(*lines)++;
	while (instr_arr[i])
	{
		if (ft_strncmp(instr_arr[i], "sa\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "sb\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "ss\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "pa\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "pb\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "ra\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "rb\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "rr\n", 3) != 0
			&& ft_strncmp(instr_arr[i], "rra\n", 4) != 0
			&& ft_strncmp(instr_arr[i], "rrb\n", 4) != 0
			&& ft_strncmp(instr_arr[i], "rrr\n", 4) != 0)
			return (0);
		i++;
	}
	//*lines = i;
	ft_printf("lines = %d\n", *lines);
	return (1);
}
