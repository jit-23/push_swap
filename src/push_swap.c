/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:02:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/19 17:01:32 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_swap_args(t_stack **a, t_stack **b, int argc)
{
	if (argc == 2)
	{
		if (sorted(*a))
			sa(a);
		delete_lst(a, lst_size(a));
		exit (1);
	}
	else if (argc == 3)
		quick_sort(a);
	else if (argc > 3)
		turk(a, b);
}

void push_swap_string(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if (sorted(*a))
			sa(a);
	}
	else if (size == 3)
		quick_sort(a);
	else if (size > 3)
		turk(a, b);
}

void	push_swap(t_stack **a, t_stack **b, char **args, int argc)
{
	if (ft_strchr(args[0], ' '))
	{
		handle_string(args[0], a);
		push_swap_string(a, b,lst_size(a));
	}
	else
	{
		handle_args(argc, args, a);
		push_swap_args(a,b,argc);
	}
}
