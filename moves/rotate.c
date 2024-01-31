/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:27:31 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 03:51:30 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_stack **head)
{
	t_stack *a;
	t_stack *last;

	a = (*head);
	last = (ft_lstlast(*head));
	a = a->next;
	a->prev = 0;
	//printf("last->next->next %d\n", last->next->next->x);	
	last->next = (*head);
	last->next->next = 0;
	(*head) = a;
	//printf("heeeead - %d\n", (*head)->x);
}
void ra(t_stack **head)
{
	ft_printf("ra\n");
	rotate(head);
}

void rb(t_stack **head)
{
	ft_printf("rb\n");
	rotate(head);
}

void rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
