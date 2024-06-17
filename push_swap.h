/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:42:42 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/17 12:59:52 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		*convert_args(char **argv, int *size);
int		is_arg_number(char *str);
int		check_args(int *arr, int size, char **argv);
void    swap_one(int *stack, int size);
void	swap_both(int *a, int *b, int size_a, int size_b);
void	push_num(int **s1, int **s2, int *size_s1, int *size_s2);
void	rotate_one(int *stack, const int size, char c);
void	rotate_both(int *a, int *b, int size_a, int size_b);
void 	rrotate_one(int *stack, const int size, char c);
void	rrotate_both(int *a, int *b, int size_a, int size_b);
void	sorting(int **a, int **b, int *size_a, int *size_b);

#endif