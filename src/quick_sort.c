/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:26 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 23:02:26 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_stack **head)
{
	t_stack *big;
	
	sorted(head);
	big = biggest_nbr(head);
	printf("(*head)->x = %d\nbig->x = %d\n", (*head)->x, big->x );
	if ((*head)->x == big->x) //input 3 2 1 || //output 2 1 3
		ra(head); //output 2 1 3 || *ignore
	else if ((*head)->next->x == big->x) //input 2 3 1 ||  
	{
		printf("(*head)->x = %d\nbig->x = %d\n", (*head)->x, big->x );
		rra(head);
	}
	if ((*head)->x > (*head)->next->x) //input 2 1 3
		sa(head);//output 1 2 3
	t_stack *a = (*head);
	while((a != NULL))
	{
		printf("a - %d\n", a->x);
		a = a->next;
	}
}
int sorted(t_stack **head)
{
	t_stack *tmp;
	long nbr;

	tmp = (*head);
	nbr = -2147483649;
	while(tmp != NULL)
	{
		if (nbr > tmp->x)
			return 1;
		else
		{
			printf("------\n");
			printf("nbr = %ld\ntmp->x = %d\n", nbr,tmp->x);
			nbr = tmp->x;
			printf("------\n");
			printf("nbr pos tmp = %ld\n", nbr);
		}
		tmp = tmp->next;
	}
	printf("sorted\n");
	exit(1);
	 // retorna 0 se organizado
}
t_stack *biggest_nbr(t_stack **head)
{
	t_stack *tmp;
	t_stack *big;
	printf("----------\n");
	big = (t_stack *)malloc(sizeof(t_stack));
	big->x = 0;
	tmp = (*head);
	printf("big = %d\n", big->x);
	while(tmp != NULL)
	{
		// printf("tmp->x = %d\n", tmp->x);
		// printf("big = %d\n", big->x);
		if (big->x < tmp->x)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_stack *smallest_nbr(t_stack **head)
{
	t_stack *tmp;
	t_stack *small;

	small = (t_stack *)malloc(sizeof(t_stack));
	small->x = 0;
	tmp = (*head);
	while(tmp->next != NULL)
	{
		if (small->x > tmp->x)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}