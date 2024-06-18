/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:46:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/18 19:49:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	write_err(void)
{
	char	file[6];

	fd = open("out.txt", O_RDWR | O_CREAT | O_EXCL | 0644);
	if (fd == -1)
		return ;
	
	read(fd, file, 6);
	ft_printf("%s", file);
	exit(fd);
}*/

int	main(int argc, char *argv[])
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	**strs;

	size_a = 0;
	size_b = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = &argv[1];
	a = convert_args(strs, &size_a);
	if (check_args(a, size_a, strs))
	{
		free(a);
		write(2, "Error\n", 6);
		return (0);
	}
	b = NULL;
	/*ft_printf("Stack a before sorting:\n");
	int i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");*/
	sorting(&a, &b, &size_a, &size_b);
	/*ft_printf("Stack a after sorting:\n");
	int i = 0;
	while (i < size_a)
	{
		ft_printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	ft_printf("\n");*/

	free(a);
	free(b);
	return (0);
}
