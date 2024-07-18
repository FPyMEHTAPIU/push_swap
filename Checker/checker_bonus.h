/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:39:34 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/18 17:03:16 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECER_BONUS_H

# include "../push_swap.h"

# ifndef INSTR_SIZE
#  define INSTR_SIZE 15
# endif

void	choose_rotation(char *instructions, t_stack **a, t_stack **b);
void	checker(char **instructions, t_stack **a, int *size_a);

#endif