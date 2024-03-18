/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:23:43 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/24 21:10:29 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	this function will transfer the first link
	of the stack a(src) to the stack b(dst)
 */
void	push(t_stack **src, t_stack **dest)
{
	if (!*src)
	{
		printf("no src stack\n");
		return ;
	}
	if (!*dest)
	{
		(*dest) = (*src);
		(*src)->next->prev = 0;
		(*src) = (*src)->next;
		(*dest)->next = 0;
		(*dest)->prev = 0;
		return ;
	}
	(*dest)->prev = (*src);
	(*src)->prev = 0;
	(*src) = (*src)->next;
	(*dest)->prev->next = (*dest);
	(*dest) = (*dest)->prev;
}

void	pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}

void	pa(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(b, a);
}
