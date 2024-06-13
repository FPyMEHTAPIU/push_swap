/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:42:42 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/13 12:42:23 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

int		*convert_args(char **argv, int *size);
int		is_arg_number(char *str);
int		check_args(int *arr, int size, char **argv);
void    swap_one(int *stack);
void	swap_both(int *a, int *b);
int		*copy_stack(int *stack, int size);
void	push_num(int *s1, int *s2, int *size_s1, int *size_s2);

#endif