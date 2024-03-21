/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:36:38 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/21 00:12:05 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
static void    rotate_both(t_stack **a, t_stack **b)
{
    rotate(a);
	rotate(b);
}

static void reverse_rotate_both(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}

void	check_move(t_stack **a, t_stack **b, char *cmd)
{
	if (!(ft_strncmp(cmd, "sa\n", sizeof("sa\n"))))
		swap(a);
	else if (!(ft_strncmp(cmd, "sb\n", sizeof("sb\n"))))
		swap(b);
	else if (!(ft_strncmp(cmd, "ra\n",sizeof("ra\n"))))
		rotate(a);
	else if (!(ft_strncmp(cmd, "rb\n", sizeof("rb\n"))))
		rotate(b);
	else if (!(ft_strncmp(cmd, "rr\n", sizeof("rr\n"))))
        rotate_both(a,b);
	else if (!(ft_strncmp(cmd, "rra\n", sizeof("rra\n"))))
		reverse_rotate(a);
	else if (!(ft_strncmp(cmd, "rrb\n", sizeof("rrb\n"))))
		reverse_rotate(b);
	else if (!(ft_strncmp(cmd, "rrr\n", sizeof("rrr\n"))))
        reverse_rotate_both(a,b);
	else if (!(ft_strncmp(cmd, "pa\n", sizeof("pa\n"))))
		push(b,a);
	else if (!(ft_strncmp(cmd, "pb\n", sizeof("pb\n"))))
		push(a,b);
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}
