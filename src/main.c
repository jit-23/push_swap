/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/02 20:09:06 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_swap(t_stack **a, t_stack **b, char **args, int argc)
{
	handle_args(argc, args, a);
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
}
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	argc--;
	if (argc == 1) // if no numbers
		return (ft_printf("Error\n"), 1);
	else
		push_swap(&a, &b, &argv[1], argc);
	delete_lst(&a, lst_size(&a));
	return (0);
}
