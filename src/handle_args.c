/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:40:23 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/25 17:27:41 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* void	delete_nbrs(int *nbrs, int size)
{
	size++;
	size--:
	free(nbrs);
} */


void handle_args(int size, char **argv, t_stack *a)
{
    int *nbrs;
    int i;
	//t_stack *a;
	
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
	delete_lst(a);
	//t_stack *tmp;
	//t_stack *next;
	// tmp = a;
	// //
	// while(tmp != NULL) //end of handeling-string
	// {
	// 	printf("%d\n", tmp->x);
	// 	tmp = tmp->next;
	// }
	//////////////////////// free all mem(a and nbr)
	//tmp = head;
	//printf("(1)tmp->x = %d\n", tmp->x);
	//if (a)
	//delete_lst(a);
	//delete_nbrs(nbrs, size);
	free(nbrs);
	//while(tmp != NULL)
	//{
	//	next = tmp->next;
	//	free(tmp);
	//	tmp = next;  
	//}
	//head = NULL;
}