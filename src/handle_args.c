/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:40:23 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/21 03:21:19 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	repete_nbrs(long *nbr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i;
		while (j + 1 < size)
		{
			if (nbr[i] == nbr[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	limit_value(long *nbr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nbr[i] > 2147483647 || nbr[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	not_int_util(char **argv, t_index index)
{
	while (argv[index.i][index.j])
	{
		if (index.j == 0)
		{
			if (ft_isdigit(argv[index.i][index.j]) == 1 ||
				argv[index.i][index.j] == '-')
				index.j++;
			else
				return (1);
		}
		else
		{
			if (ft_isdigit(argv[index.i][index.j]) == 1)
				index.j++;
			else
				return (1);
		}
	}
	return (0);
}

int	not_int(char **argv)
{
	t_index	index;

	index.i = -1;
	while (argv[++index.i])
	{
		index.j = 0;
		if (1 == not_int_util(argv, index))
			return (1);
	}
	return (0);
}

void	handle_args(int size, char **argv, t_stack **a)
{
	long	*nbrs;
	int		i;

	i = -1;
	if (not_int(argv) == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	*a = (t_stack *)malloc(sizeof(t_stack));
	init_head((*a));
	nbrs = (long *)malloc(sizeof(long) * (size));
	if (!nbrs)
		exit(1);
	while (++i < size)
		nbrs[i] = ft_atoll((argv[i]));
	if (repete_nbrs(nbrs, size) == 1 || limit_value(nbrs, size) == 1)
	{
		ft_printf("Error\n");
		free(nbrs);
		delete_lst(a, lst_size(a));
		exit(1);
	}
	fill_stack(nbrs, a, size);
	free(nbrs);
}
