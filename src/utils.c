/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:42:11 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 23:06:05 by fde-jesu         ###   ########.fr       */
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

void delete_lst(t_stack **head, int size)
{
	t_stack *del;
	int i;

	i = -1;
	del = (*head);
	while(++i < size)
	{
		del = del->next;
		free(*head);
		(*head) = del;
	}
}


t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	fill_stack(int *nbrs, t_stack **head, int size)
{
    int i;
    t_stack *prev;
	t_stack *a;

    i = 0;
    a = (*head);
	prev = (*head); 
    while (i < size)
    {
        if (i == 0)
		{
			a->x = nbrs[i];
			a->prev = NULL ;
		}
        else
        {
            a->next = ft_lstnew(nbrs[i]);
            a = a->next;
			a->prev = prev;
			prev = prev->next;
        }
        i++;
    }
	a->next = NULL;
}