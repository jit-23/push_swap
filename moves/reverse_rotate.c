/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:10:19 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/25 00:22:10 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void reverse_rotate(t_stack **head)
// {
// 	//t_stack *a;
// 	t_stack *last;

// 	last = ft_lstlast(*head);

// 	//last->next = a;
// 	//last->prev->next = 0;
// 	//last->prev = 0;
// 	//a->prev = last;
// 	//a = last;
// 	last->prev->next = 0;
// 	last->prev = 0;
// 	last->next =(*head);
// 	(*head)->prev = last;
// 	(*head) = last;
// }

void	reverse_rotate(t_stack **stack) // hmmm  better substitute this
{
	t_stack	*head;
	t_stack	*tail;
	if (lst_size(stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
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
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
