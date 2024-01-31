/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:38:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 22:47:14 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_size(t_stack **head)
{
	t_stack *node;
	int		size;

	node = (*head);
	size = 0;
	while(node != NULL)
	{
		size++;
		node = node->next;
	}
	return (size);
}
