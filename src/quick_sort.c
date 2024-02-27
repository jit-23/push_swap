/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:26 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/25 00:16:13 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_stack **head)
{
	t_stack *big;
	
	big = biggest_nbr(*head);
	if ((*head)->x == big->x) //input 3 2 1 || //output 2 1 3
		ra(head); //output 2 1 3 || *ignore
	else if ((*head)->next->x == big->x) //input 2 3 1 ||  
		rra(head);
	if ((*head)->x > (*head)->next->x) //input 2 1 3
		sa(head);//output 1 2 3
	// t_stack *a = (*head);
	// while((a != NULL))
	// {
	// 	printf("a - %d\n", a->x);
	// 	a = a->next;
	// }
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
			nbr = tmp->x;
		tmp = tmp->next;
	}
	printf("sorted\n");
	exit(1);
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