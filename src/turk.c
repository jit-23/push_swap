/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:24:32 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:19 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
static void put_index(t_stack *head, int middle)
{
	int i;

	i = 0;
	printf("middle = %d\n", middle);
	while(head)
	{
		head->index = i++;
		if (head->index <= middle)// higher than middle
			head->above_middle = 1; // 1 true
		else
			head->above_middle = 0; // 0 false
		head = head->next;
	}
	printf("..............\n");
	return ;
}
void turk(t_stack **a, t_stack **b)
{
	//t_stack *m;
	//t_stack *n;
	t_stack *smallest;
	while (lst_size(a) > 3)
		pb(a, b);
	quick_sort(a);
	//n = (*b);
	while((*b))
	{
		init_nodes(a,b);
		move_nodes(a,b);
		printf("........\n");
	}
	smallest = smallest_nbr(*a);
	if ((*a) != smallest)
	{
		if (smallest->above_middle == 1)
			while((*a) != smallest)
				ra(a);
		else
			while((*a) != smallest)
				rra(a);
	}
	while(*a)
	{
		printf("a - %d\n", (*a)->x);
		(*a) = (*a)->next;
	}
}

void	big_match(t_stack **a, t_stack **b) // looks for the bigger most close number in the other stack 
{
	long val;
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_b = (*b);
	while(tmp_b)
	{
		//printf("tmp_b = %d\n\n", tmp_b->x);
		tmp_a = (*a);
		val = LONG_MAX;
		while (tmp_a)
		{
		//	printf("tmp_a = %d\n", tmp_a->x);
			if (val > tmp_a->x && tmp_a->x > tmp_b->x)
			{
				val = tmp_a->x;
				tmp_b->match = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (val == LONG_MAX) // only happens if there is no bigger number in stack a, so 
			tmp_b->match = smallest_nbr(*a);// we asign the smallest to it
		tmp_b = tmp_b->next;
	}
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

void	init_nodes(t_stack **a, t_stack **b)
{
	put_index(*a, lst_size(a)/2);
	put_index(*b, lst_size(b)/2);
	big_match(a, b);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	// 1 - first i find the lowest with value to push on the linked list, 
	// 2 - then with that value, i find the first with that same value 
	// 3 - after that i will rotate(rr or rrr) to the point where i have at either 
	// 	   the lowest_push_node or the lowest_push_node->match on top of designated stack, then i just
	//	   adjust the one that is not on top, push the b node to a, then get out and 
	//     repeat the loop again (line 37 )
	//printf("flag: move_nodes\n");
	t_stack *node2push;
	push_value(*a,*b); // i will give the push val to every node
	node2push = cheappest_push(*b); //i will find the lowet val to push
	r_till_top(a, b, node2push);
	r_adjust(a, b, node2push);
	//printf("(*a)->x = %d\n(*b)->x = %d\n", (*a)->x, (*b)->x);
	pa(a,b);
}


/* //m = (*a);
		//n = (*b);
		//while(m)
		//{
		//	printf("a - %d\n", (m)->x);
		//	(m) = (m)->next;	
		//}
		//printf("........\n");
		//if (n)
		//{
		//	while(n)
		//	{
		//		printf("b - %d\n", (n)->x);
		//		(n) = (n)->next;	
		//	}
		//} */



/* // while((*a))
	// {
	// 	printf("======================\n");
	// 	printf("head = %d\n", (*a)->x);
	// 	printf("head index = %d\n", (*a)->index);
	// 	printf("head_above = %d\n", (*a)->above_middle);
	// 	printf("smallest->x = %d\n", smallest->x);
	// 	printf("smallest above? = %d\n", smallest->above_middle);
	// 	(*a) = (*a)->next;
	// }
	// while((*a) != smallest)
	// {
	// 	printf("head = %d", (*a)->x);
	// 	printf("above->x = %d\n", smallest->x);
	// 	printf("above = %d\n", (*a)->above_middle);
	// 	ra(a);
	// } */


/* // m = (*a);
	// while(m)
	// {
	//  printf("m - %d\n", (m)->x);
	//  (m) = (m)->next;
	// }
	// printf("////////////////////////////\n");
	// while(n)
	// {
	//  printf("n - %d\n", (n)->x);
	//  (n) = (n)->next;
	// } */