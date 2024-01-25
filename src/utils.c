/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:42:11 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/25 17:30:10 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int x)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->x = x;
	new_node->next = NULL;
	return (new_node);
}

void delete_lst(t_stack *head)
{
	t_stack *next;
	t_stack *delete;

	delete = head;
	//printf("flag1\n");
	//printf("flag2\n");

//	next = NULL;
	while(delete != NULL)
	{
		printf("%d\n",delete->x);
		next = delete->next;
		free(delete);
		delete = next;
	}
//	head = NULL;
}

void	fill_stack(int *nbrs, t_stack *head, int size)
{
    int i;
    t_stack *a;

    i = 0;
    a = head;
    while(i < size)
    {
        if (i == 0)
			a->x = nbrs[i];
        else
        {
            a->next = ft_lstnew(nbrs[i]);
            a = a->next;
        }
        i++;
    }
}
