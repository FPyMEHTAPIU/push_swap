/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:39:34 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/23 14:04:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECER_BONUS_H

# include "../push_swap.h"

# ifndef INSTR_SIZE
#  define INSTR_SIZE 15
# endif

void	choose_rotation(char *instructions, t_stack **a, t_stack **b);
void	choose_swap(t_stack **a, t_stack **b, char c);
int		checker(char **instructions, t_stack **a, int *size_a, int lines);
int		check_instructions(char **instr_arr, int *lines);

#endif