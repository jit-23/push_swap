/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:42:11 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/24 21:07:51 by fde-jesu         ###   ########.fr       */
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

void	delete_lst(t_stack **head, int size)
{
	t_stack	*del;
	int		i;

	i = -1;
	del = (*head);
	while (++i < size)
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

int	lst_size(t_stack **head)
{
	t_stack *node;
	int size;
	if (!(*head))
		return (0);
	node = (*head);
	size = 0;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}
	return (size);
}