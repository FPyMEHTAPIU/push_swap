/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:03:49 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/12 17:04:11 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	to_pos(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}