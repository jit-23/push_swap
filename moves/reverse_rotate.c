/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:10:19 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/19 23:28:16 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (lst_size(stack) < 2)
		return ;
	head = (*stack);
	last = ft_lstlast(*stack);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = (*stack);
	(*stack) = last;
}

void	rra(t_stack **head)
{
	ft_printf("rra\n");
	reverse_rotate(head);
}

void	rrb(t_stack **head)
{
	ft_printf("rrb\n");
	reverse_rotate(head);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
