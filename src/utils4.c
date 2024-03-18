/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:32:44 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/18 17:49:40 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_a2b(t_stack **a, t_stack **b)
{
	t_stack	*node2push;

	push_value(*b, *a);
	node2push = find_cheappest_push(*a);
	r_till_top(b, a, node2push);
	r_adjust(b, a, node2push, 'a');
	pb(a, b);
}

void	move_b2a(t_stack **a, t_stack **b)
{
	t_stack	*node2push;

	push_value(*a, *b);
	node2push = find_cheappest_push(*b);
	r_till_top(a, b, node2push);
	r_adjust(a, b, node2push, 'b');
	pa(a, b);
}

void	r_till_top(t_stack **dest, t_stack **src, t_stack *n2p)
{
	if (n2p->above_middle == 1 && n2p->match->above_middle == 1)
		while ((*src) != n2p && (*dest) != n2p->match)
			rr(src, dest);
	else if (n2p->above_middle == 0 && n2p->match->above_middle == 0)
		while ((*src) != n2p && (*dest) != n2p->match)
			rrr(src, dest);
}

void	r_adjust(t_stack **dest_node, t_stack **src_node, t_stack *n2p,
				char stack_to_take)
{
	rotate_src_node(src_node, n2p, stack_to_take);
	rotate_dest_node(dest_node, n2p, stack_to_take);
}
