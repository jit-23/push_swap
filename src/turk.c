/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:24:32 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/29 02:45:51 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void adjust_tail(t_stack **a, t_stack **b, char big_or_small, t_stack *tail)
{
	if (big_or_small == 'b')
	{
		tail = biggest_nbr(*b);
		while(tail != (*b))
		{
			if (tail->above_middle == 1)
				rb(b);
			else if (tail->above_middle == 0)
				rrb(b);
	}
	}
	else if (big_or_small == 's')
	{
		tail = smallest_nbr(*a);
		while(tail != (*a))
		{
			if (tail->above_middle == 1)
				ra(a);
			else if (tail->above_middle == 0)
				rra(a);
	}
	}
}

void turk(t_stack **a, t_stack **b)
{
	t_stack *big_nbr;
	t_stack *small_nbr;
	
	if (lst_size(a) > 3)
		pb(a,b);
	if (lst_size(a) > 3)
		pb(a, b);
	while(lst_size(a) > 3)
	{
		init_nodes(a, b, 'a');
		move_a2b(a,b);
	}
	quick_sort(a);
	big_nbr = biggest_nbr(*b);
	adjust_tail(a, b, 'b', big_nbr);
	while((*b))
	{
		init_nodes(a,b,'b');
		move_b2a(a,b);
	}
	small_nbr = smallest_nbr(*a);
	adjust_tail(a, b, 's', small_nbr);
	
}





t_stack *smallest_nbr(t_stack *head)
{
	t_stack *small;

	small = (t_stack *)malloc(sizeof(t_stack));
	small->x = INT_MAX;
	while(head != NULL)
	{
		if (small->x > head->x)
			small = head;
		head = head->next;
	}
	return (small);
}


t_stack *biggest_nbr(t_stack *head)
{
	t_stack *big;
	big = (t_stack *)malloc(sizeof(t_stack));
	big->x = INT_MIN;
	// printf("big = %d\n", big->x);
	while(head != NULL)
	{
		if (big->x < head->x)
			big = head;
		head = head->next;
	}
	return (big);
}
