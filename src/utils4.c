/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:32:44 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/29 02:35:42 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_a2b(t_stack **a, t_stack **b)
{
	t_stack	*node2push;

	push_value(*b, *a);                 
		// i will give the push val to every node
	node2push = find_cheappest_push(*a);
		// i will find the lowet val to push form A TO B
	r_till_top(b, a, node2push);
	r_adjust(b, a, node2push, 'a');
	pb(a, b);
}
void	move_b2a(t_stack **a, t_stack **b)
{
	t_stack	*node2push;

	push_value(*a, *b);                 
		// i will give the push val to every node
	node2push = find_cheappest_push(*b); // i will find the lowet val to push
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