/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:23:43 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/30 21:56:41 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
	this function will transfer the first link
	of the stack a(src) to the stack b(dst)
 */
void	push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;
	if (!*src)
	{
		perror("no stack");
		return ;
	}
	if (!*dest)
	{
		(*dest) = (*src);
		(*src)->next->prev = 0;
		(*src) = (*src)->next;
		(*dest)->next = 0;
		(*dest)->prev = 0;
	}
	else
	{
		tmp = (*src);
		(*dest)->prev = tmp;
		tmp->next = (*dest);
		(*dest) = tmp;
		(*src) = (*src)->next;
		(*src)->prev = 0;
	}
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
// printf(stack b pos modify)
/* 	while((*dest) != NULL)
	{
		printf("(*dest) = %d\n", (*dest)->x);
		(*dest) = (*dest)->next;
	} */
