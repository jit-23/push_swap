/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:26 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/18 19:22:00 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_stack **head)
{
	t_stack	*big;

	big = biggest_nbr(*head);
	if ((*head)->x == big->x)
		ra(head);
	else if ((*head)->next->x == big->x)
		rra(head);
	if ((*head)->x > (*head)->next->x)
		sa(head);
}

int	sorted(t_stack *head)
{
	long	nbr;

	nbr = -2147483648;
	while (head != NULL)
	{
		if (nbr > head->x)
			return (1);
		else
			nbr = head->x;
		head = head->next;
	}
	return (0);
}
