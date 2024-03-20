/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:27:31 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/19 23:28:19 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*a;
	t_stack	*last;

	if (lst_size(head) < 2)
		return ;
	a = (*head);
	last = (ft_lstlast(*head));
	a = a->next;
	a->prev = 0;
	last->next = (*head);
	last->next->next = 0;
	(*head) = a;
}

void	ra(t_stack **head)
{
	ft_printf("ra\n");
	rotate(head);
}

void	rb(t_stack **head)
{
	ft_printf("rb\n");
	rotate(head);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
