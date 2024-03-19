/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/19 21:08:43 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack(long *nbrs, t_stack **head, int size)
{
	int		i;
	t_stack	*prev;
	t_stack	*a;

	i = 0;
	a = (*head);
	prev = (*head);
	while (i < size)
	{
		if (i == 0)
		{
			a->x = nbrs[i];
			a->prev = NULL;
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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (ft_printf("error\n"), 1);
	else
		push_swap(&a, &b, &argv[1], --argc);
	delete_lst(&a, lst_size(&a));
	return (0);
}


/* static void	push_swap(t_stack **a, t_stack **b, char **args, int argc)
{
	handle_string(args[0], a);
//	handle_args(argc, args, a);
	if (argc == 2)
	{
		if (!sorted(*a))
			sa(a);
	}
	else if (argc == 3)
	{
		quick_sort(a);
		delete_lst(a, lst_size(a));
		exit(1);
	}
	else if (argc > 3)
		turk(a, b);
} */