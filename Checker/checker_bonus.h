/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:39:34 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/25 11:35:01 by msavelie         ###   ########.fr       */
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
int		push_to_stack(t_stack **s1, t_stack **s2, int *size_s1, int *size_s2);
int		check_capacity(t_stack **s, int size_s, int pb_instr, int *size_a);
//int		free_b(t_stack **b, int size_b, int pb_instr);
int		free_b(t_stack **a, t_stack **b, int size_a, int size_b);
int		free_a(t_stack **a, int *size_a);

#endif