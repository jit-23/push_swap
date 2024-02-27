/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:38:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/27 16:38:27 by fde-jesu         ###   ########.fr       */
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

void push_value(t_stack *a, t_stack *b)// vou dar a cada node o valor do push do mesmo,  
{
	int len_a;
	int len_b;

	len_a = lst_size(&a);
	len_b = lst_size(&b);
	while(b)
	{
		b->push_value = b->index;
		if (b->above_middle == 0)
			b->push_value = len_b - b->index;
		if (b->match->above_middle == 1)
			b->push_value += b->match->index;
		else
			b->push_value += len_a - b->match->index;
		b = b->next;
	}
}

t_stack	*cheappest_push(t_stack *b) // vou encontrar o primeiro node com o valor equivalente ao mais barato
{
	int lowest;
	t_stack *tmp_b;
	t_stack *lowest_node;

	lowest = INT_MAX;
	tmp_b = b;
	while(tmp_b)
	{
		if (lowest > tmp_b->push_value)
		{
			lowest = tmp_b->push_value;
			lowest_node = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	return (lowest_node);
}

void	r_till_top(t_stack **a, t_stack **b, t_stack *lowest_push)
{
	// t_stack *tmp_a;
	// t_stack *tmp_b;

	// tmp_a = (*a);
	// tmp_b = (*b);
	if (lowest_push->above_middle == 1 && lowest_push->match->above_middle == 1)
	{
		while((*b) != lowest_push && (*a) != lowest_push->match)
			rr(a, b);	
	}
	else if(lowest_push->above_middle == 0 && lowest_push->match->above_middle == 0)
	{
		while((*b) != lowest_push && (*a) != lowest_push->match)
			rrr(a, b);
	}	
	
// este loop vai rodar ambos os nodes ate ter ou o node certo em a no topo ou o  node de b no topo
// agra o que devo fazer e acertar com o que n esta no topo.																																																																													)		
}

void r_adjust(t_stack **a, t_stack **b, t_stack *n2p)
{
	if ((*a) != n2p->match)
	{
		if (n2p->match->above_middle == 1)
			while((*a) != n2p->match)
				ra(a);
		else
			while((*a) != n2p->match)
				rra(a);
	}	
	else if ((*b) != n2p)
	{	
		if (n2p->match->above_middle == 1)
			while((*b) != n2p)
				rb(b);
		else
			while((*b) != n2p)
				rrb(b);		
	}
}
