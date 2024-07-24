/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:34:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/24 22:58:14 by msavelie         ###   ########.fr       */
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

int	push_to_stack(t_stack **s1, t_stack **s2, int *size_s1, int *size_s2)
{
	static int	pb_instr;
	
	if (!(*s1) || *size_s1 == 0)
		return (1);
	if (ft_last(*s1)->type == 'b')
	{
		if (!check_capacity(s2, *size_s2, pb_instr, -(*size_s1)))
			return (free_b(s2, s1, *size_s2, *size_s1));
		push_num(s1, s2, size_s1, size_s2);
		ft_last(*s2)->type = 'a';
		ft_last(*s2)->was_pushed = 1;
	}
	else if (ft_last(*s1)->type == 'a')
	{
		if (!check_capacity(s2, *size_s2, pb_instr, *size_s1))
			return (free_a(s1, size_s1));
		push_num(s1, s2, size_s1, size_s2);
		pb_instr++;
		ft_last(*s2)->type = 'b';
	}
	return (1);
}
