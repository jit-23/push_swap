/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:10:19 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/30 21:58:32 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_rotate(t_stack **head)
{
	t_stack *a;
	t_stack *last;

	a = (*head);
	last = (ft_lstlast(*head));

	last->prev->next = 0;
	last->prev = 0;
	last->next = a;

	a->next->prev = last;
	(*head) = last;
}

void rra(t_stack **head)
{
	ft_printf("rra\n");
	reverse_rotate(head);
}

void rrb(t_stack **head)
{
	ft_printf("rrb\n");
	reverse_rotate(head);
}

void rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
