/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:31:50 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/18 19:25:09 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*a;
	t_stack	*b;

	a = (*head);
	b = a->next;
	a->prev = b;
	a->next = b->next;
	b->prev = 0;
	b->next->prev = a;
	b->next = a;
	(*head) = b;
}

void	sa(t_stack **head)
{
	ft_printf("sa\n");
	swap(head);
}

void	sb(t_stack **head)
{
	ft_printf("sb\n");
	swap(head);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
