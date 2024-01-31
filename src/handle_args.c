/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:40:23 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 18:05:03 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* void	delete_nbrs(int *nbrs, int size)
{
	size++;
	size--:
	free(nbrs);
} */


void handle_args(int size, char **argv, t_stack **a)
{
    int *nbrs;
    int i;

	*a = (t_stack *)malloc(sizeof(t_stack));
    i = -1;
    nbrs = (int *)malloc(sizeof(int) * (size));
	if (!nbrs)
	{
		free(nbrs);
		return ;
	}
    while(++i < size)
	{
        nbrs[i] = ft_atoll((argv[i]));

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
	i = 0;
	fill_stack(nbrs, a, size);
	free(nbrs);
}

	// tmp = a;
	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->x);
	// 	tmp = tmp->next;
	// 	i++;
	// }