/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:34:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 14:03:20 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	choose_rotation(char *instructions, t_stack **a, t_stack **b)
{
	if (instructions[1] == 'a')
		rotate_one(*a, 0);
	else if (instructions[1] == 'b')
		rotate_one(*b, 0);
	else if (instructions[1] == 'r')
	{
		if (instructions[2] == 'a')
			rrotate_one(*a, 0);
		else if (instructions[2] == 'b')
			rrotate_one(*b, 0);
		else if (instructions[2] == 'r')
			rrotate_both(*a, *b, 0);
		else
			rotate_both(*a, *b, 0);
	}
	else
	{
		write(2, "Error\n", 6);
		return ;
	}
}

void	choose_swap(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		swap_one(*a, 0);
	else if (c == 'b')
		swap_one(*b, 0);
	else if (c == 's')
		swap_both(*a, *b, 0);
}
