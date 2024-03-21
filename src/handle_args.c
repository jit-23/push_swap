/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:40:23 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/20 21:24:19 by fde-jesu         ###   ########.fr       */
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

int not_int(char ** argv)
{
	int i;
	int j;
	i = -1;
	while(argv[++i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (j == 0)
				if (ft_isdigit(argv[i][j]) == 1 || argv[i][j] == '-') // if number or '-'
					j++;
				else
					return (1);
			else
				if (ft_isdigit(argv[i][j]) == 1)
					j++;
				else
					return (1); 
		}

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
