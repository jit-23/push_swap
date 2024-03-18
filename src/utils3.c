/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:20:38 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/29 02:32:02 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	put_index(t_stack *head, int middle)
{
	int	i;

	i = 0;
	while (head)
	{
		head->index = i++;
		if (head->index <= middle)  // higher than middle
			head->above_middle = 1; // 1 true
		else
			head->above_middle = 0; // 0 false
		head = head->next;
	}
}

void	init_nodes(t_stack **a, t_stack **b, char node2take)
{
	put_index((*a), lst_size(a) / 2);
	put_index((*b), lst_size(b) / 2);
	if (node2take == 'a')
		small_match(a, b);
	else
		big_match(a, b);
}

void	big_match(t_stack **a, t_stack **b)
		// looks for the bigger most close number in the other stack
{
	long val;
	t_stack *tmp_a;
	t_stack *tmp_b;
	tmp_b = (*b);
	while (tmp_b)
	{
		tmp_a = (*a);
		val = INT_MAX;
		while (tmp_a)
		{
			if (val > tmp_a->x && tmp_a->x > tmp_b->x)
			{
				val = tmp_a->x;
				tmp_b->match = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (val == INT_MAX)                 
			// only happens if there is no bigger number in stack a, so
			tmp_b->match = smallest_nbr(*a); // we asign the smallest to it
		tmp_b = tmp_b->next;
	}
}

void	small_match(t_stack **a, t_stack **b)
		// looks for the bigger most close number in the other stack
{
	int val;
	t_stack *tmp_b;
	t_stack *tmp_a;

	tmp_a = (*a);
	while (tmp_a)
	{
		val = INT_MIN;
		tmp_b = (*b);
		while (tmp_b)
		{
			if (tmp_a->x > tmp_b->x && tmp_b->x > val)
			{
				val = tmp_b->x;
				tmp_a->match = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (val == INT_MIN)
			tmp_a->match = biggest_nbr(*b);
		tmp_a = tmp_a->next;
	}
}