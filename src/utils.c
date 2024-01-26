/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:42:11 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/26 04:07:57 by fde-jesu         ###   ########.fr       */
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

void delete_lst(t_stack *head, int size)
{
	t_stack *del;
	int i;

	i = 0;
	del = head;
	while(i < size)
	{
		printf("%d\n",del->x);
		del = del->next;
		free(head);
		head = del;
		i++;
	}
}

void	fill_stack(int *nbrs, t_stack *head, int size)
{
    int i;
    t_stack *prev;
    t_stack *a;

    i = 0;
    a = head;
	prev = head;
    while(i < size)
    {
        if (i == 0)
			a->x = nbrs[i];
        else
        {
            a->next = ft_lstnew(nbrs[i]);
            a = a->next;
			a->prev = prev;
			prev = prev->next;
        }
        i++;
		if (i == size)
		{
			a->next = head;
			prev->prev = a;
		}
    }
}
