/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:47:53 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 11:54:38 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function frees all allocated if they exist and print error
int	invalid_input(int argc, char **strs, int size_a, t_stack **a)
{
	if (argc == 2)
		free_strs(strs, size_a);
	return (free_and_ret(strs, a, size_a, 5));
}
