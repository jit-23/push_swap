/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:26 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/29 18:00:20 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_stack **head)
{
	t_stack	*big;

	big = biggest_nbr(*head);
	printf("big%d\n", big->x);
	if ((*head)->x == big->x)            // input 3 2 1 || //output 2 1 3
		ra(head);                        // output 2 1 3 || *ignore
	else if ((*head)->next->x == big->x) // input 2 3 1 ||
		rra(head);
	if ((*head)->x > (*head)->next->x) // input 2 1 3
		sa(head);                      // output 1 2 3
}
int	sorted(t_stack *head)
{
	long	nbr;

	nbr = -2147483649;
	while (head != NULL)
	{
		if (nbr > head->x)
			return (1); // 1 if not sorted
		else
			nbr = head->x;
		head = head->next;
	}
	return (0);
}
