/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:50:43 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:36:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Free temporary holder object and its arrays
void	free_holder(t_hold *holder)
{
	if (holder->a_moves)
		free(holder->a_moves);
	if (holder->b_moves)
		free(holder->b_moves);
	free(holder);
}

// Allocate memory for the temp holder 
t_hold	*create_holder(int size_a)
{
	t_hold	*holder;

	holder = malloc(sizeof(t_hold));
	if (!holder)
		return (NULL);
	holder->a_moves = malloc(sizeof(int) * size_a);
	holder->b_moves = malloc(sizeof(int) * size_a);
	if (!holder->a_moves || !holder->b_moves)
	{
		free_holder(holder);
		return (NULL);
	}
	return (holder);
}
