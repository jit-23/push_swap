/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:40:23 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/20 20:06:19 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_head(t_stack *head)
{
	head->above_middle = 0;
	head->index = 0;
	head->match = 0;
	head->next = 0;
	head->prev = 0;
	head->push_value = 0;
	head->x = 0;
}

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

/* int not_int(char ** argv)
{
	int i;
	int j;
	i = -1;
	while(argv[++i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-')
				continue ;
			else if (ft_isdigit(argv[i][j] == 0))
				return (1);
			j++;
		}
	}
	return (0);
} */

int	not_int(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
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
		printf("error\n");
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
		printf("Error\n");
		free(nbrs);
		delete_lst(a, lst_size(a));
		exit(1);
	}
	fill_stack(nbrs, a, size);
	free(nbrs);
}
