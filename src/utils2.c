/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:38:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/28 22:23:33 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(int *nbrs, t_stack **head, int size)
{
    int i;
    t_stack *prev;
	t_stack *a;

    i = 0;
    a = (*head);
	prev = (*head); 
    while (i < size)
    {
        if (i == 0)
		{
			a->x = nbrs[i];
			a->prev = NULL ;
		}
        else
        {
            a->next = ft_lstnew(nbrs[i]);
            a = a->next;
			a->prev = prev;
			prev = prev->next;
        }
        i++;
    }
	a->next = NULL;
}

void push_value(t_stack *dest, t_stack *src)
{ 
	int len_dest;// dest_list
	int len_src;//src_list
	// as duas alineias acima estao corretas se for the b -> a, caso contrario o dest e src trocam se
	len_dest = lst_size(&dest);
	len_src = lst_size(&src);
	while(src)
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

t_stack	*find_cheappest_push(t_stack *head) // vou encontrar o primeiro node com o valor equivalente ao mais barato
{
	int lowest;
	t_stack *cheappest_node;

	lowest = INT_MAX;
	while(head)
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

static void	rotate_src_node(t_stack **src_node, t_stack *n2p, char stack_to_take)
{	
	if (n2p->above_middle == 1)
	{
		while((*src_node) != n2p)
		{
			if (stack_to_take == 'a')
				ra(src_node);
			else if (stack_to_take == 'b')
				rb(src_node);
		}
	}
	else if (n2p->above_middle == 0)
	{	
		while((*src_node) != n2p)
		{
			if (stack_to_take == 'a')
				rra(src_node);
			else if (stack_to_take == 'b')
				rrb(src_node);	
		}
	}
}
// stack to take  e ...give muda dependendo do loop(primerio ou segundo)
static void	rotate_dest_node(t_stack **dest_node, t_stack *n2p, char stack_to_give) // stack_to_take  needs to be the stack that we are rotating
{
	if (n2p->match->above_middle == 1)
	{
		while((*dest_node) != n2p->match)
		{
			if (stack_to_give == 'a')
				rb(dest_node);
			else if (stack_to_give == 'b')
				ra(dest_node);	
		}
	}
	else if (n2p->match->above_middle == 0)
	{
		while((*dest_node) != n2p->match)
		{
			if (stack_to_give == 'a')
				rrb(dest_node);
			else if (stack_to_give == 'b')
				rra(dest_node);
		}
	}
}

// a e dest b e src on the last loop, otherwise is the contrary
void r_adjust(t_stack **dest_node, t_stack **src_node, t_stack *n2p, char stack_to_take)// char b
{
	rotate_src_node(src_node, n2p, stack_to_take);
	rotate_dest_node(dest_node, n2p, stack_to_take);
}