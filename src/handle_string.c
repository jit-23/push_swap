/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:19:38 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/25 17:26:02 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int repete_nbrs(int *nbr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < size - 1)
	{
		j = i;
		while(j + 1 < size)
		{
			if (nbr[i] == nbr[j + 1])
				return 1;
			j++;
		}
		i++;
	}
    return 0;
}

int	limit_value(int *nbrs, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (nbrs[i] > INT_MAX || nbrs[i] < INT_MIN)
			return (1);
		i++;
	}
	return (0);		
}

int *convert_arr(char **nbrs, int size)
{
	int i;
	int *arr;

	i = -1;
	
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit (EXIT_FAILURE);
	while(nbrs[++i])
		arr[i] = ft_atoll(nbrs[i]);
	return (arr);
}

void    handle_string(char *string, t_stack *a)
{
	char	**arr;
	int		size;
	int *nbrs;
	t_stack *tmp;

	tmp = a;
	size = ft_count(string, ' ');
    arr = ft_split(string, ' ');
	nbrs = convert_arr(arr, size);
    if (!nbrs)
	{
        printf("ERROR converting\n");
		return ;
	}
    if (repete_nbrs(nbrs, size) == 1)
	{
        printf("repeated nbrs\n");
		return ;
	} 
	if (limit_value(nbrs, size) == 1)
	{
		printf("more/less that  int \n");
		return ;
	}
	fill_stack(nbrs, a, size);
	while(tmp != NULL) //end of handeling-string
	{
		printf("%d\n", tmp->x);
		tmp = tmp->next;
	}
	delete_lst(a);
	for (int s = 0; arr[s]; s++)
		free(arr[s]);
	free(arr);
}
