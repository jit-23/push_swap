/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:17:01 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/19 17:02:53 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_arr(char **arr)
{
	int s;

	s = -1;
	while(arr[++s])
		free(arr[s]);
	free(arr);
}

static void	handle_string_util(char **arr, long *nbrs, int size, t_stack **a)
{
	if (repete_nbrs(nbrs, size) == 1 || limit_value(nbrs, size) == 1)
	{
		ft_printf("Error\n");
		free(nbrs);
		delete_lst(a, lst_size(a));
		delete_arr(arr);
		exit(1);
	}
}

void	handle_string(char *string, t_stack **a)
{
	char	**arr;
	int		size;
	long	*nbrs;
	int		i;

	i = -1;
	arr = ft_split(string, ' ');
	size = ft_count(string, ' ');
	if (not_int(arr) == 1)
	{
		printf("error\n");
		delete_arr(arr);
		exit(1);
	}
	*a = (t_stack *)malloc(sizeof(t_stack));
	init_head((*a));
	nbrs = (long *)malloc(sizeof(long) * (size));
	while(++i < size)
	{
		nbrs[i] = ft_atoll(arr[i]);
	}
	handle_string_util(arr, nbrs, size, a);
	fill_stack(nbrs, a, size);
	delete_arr(arr);
	free(nbrs);
}
