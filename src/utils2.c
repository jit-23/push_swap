/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:38:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/18 18:01:52 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_value(t_stack *dest, t_stack *src)
{
	int	len_dest;
	int	len_src;

	len_dest = lst_size(&dest);
	len_src = lst_size(&src);
	while (src)
	{
		src->push_value = src->index;
		if (src->above_middle == 0)
			src->push_value = len_src - src->index;
		if (src->match->above_middle == 1)
			src->push_value += src->match->index;
		else
			src->push_value += len_dest - src->match->index;
		src = src->next;
	}
}

t_stack	*find_cheappest_push(t_stack *head)
{
	int		lowest;
	t_stack	*cheappest_node;

	lowest = INT_MAX;
	while (head)
	{
		if (lowest > head->push_value)
		{
			lowest = head->push_value;
			cheappest_node = head;
		}
		head = head->next;
	}
	return (cheappest_node);
}

void	rotate_src_node(t_stack **src_node, t_stack *n2p,
		char stack_to_take)
{
	if (n2p->above_middle == 1)
	{
		while ((*src_node) != n2p)
		{
			if (stack_to_take == 'a')
				ra(src_node);
			else if (stack_to_take == 'b')
				rb(src_node);
		}
	}
	else if (n2p->above_middle == 0)
	{
		while ((*src_node) != n2p)
		{
			if (stack_to_take == 'a')
				rra(src_node);
			else if (stack_to_take == 'b')
				rrb(src_node);
		}
	}
}

void	rotate_dest_node(t_stack **dest_node, t_stack *n2p,
								char stack_to_give)
{
	if (n2p->match->above_middle == 1)
	{
		while ((*dest_node) != n2p->match)
		{
			if (stack_to_give == 'a')
				rb(dest_node);
			else if (stack_to_give == 'b')
				ra(dest_node);
		}
	}
	else if (n2p->match->above_middle == 0)
	{
		while ((*dest_node) != n2p->match)
		{
			if (stack_to_give == 'a')
				rrb(dest_node);
			else if (stack_to_give == 'b')
				rra(dest_node);
		}
	}
}
