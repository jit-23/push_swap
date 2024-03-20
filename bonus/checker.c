/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:07:54 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/20 19:36:36 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_line(t_stack **a, t_stack **b)
{
	char *line;

	line = " ";
	while(line)
	{
		line = get_next_line(0);
		//printf("line = %s\n", line);
		if (line)
		{
			check_move(a,b, line);
			free(line);
		}
	}
	t_stack *q;
	
	q = (*a);
	while(q)
	{
		printf("%d\n", q->x);
		q = q->next;		
	}
	if (!sorted(*a))
	{
		printf("OK");
	}
}
void	check_move(t_stack **a, t_stack **b, char *cmd)
{
	if (!(ft_strncmp(cmd, "sa", 2)))
		sa(a);
	else if (!(ft_strncmp(cmd, "sb\n", sizeof("sb\n"))))
		sb(b);
	else if (!(ft_strncmp(cmd, "ra",2)))
		ra(a);
	else if (!(ft_strncmp(cmd, "rb\n", sizeof("rb\n"))))
		rb(b);
	else if (!(ft_strncmp(cmd, "rr\n", sizeof("rr\n"))))
		rr(a,b);
	else if (!(ft_strncmp(cmd, "rra\n", sizeof("rra\n"))))
		rra(a);
	else if (!(ft_strncmp(cmd, "rrb\n", sizeof("rrb\n"))))
		rrb(b);
	else if (!(ft_strncmp(cmd, "rrr\n", sizeof("rrr\n"))))
		rrr(a,b);
	else if (!(ft_strncmp(cmd, "pa\n", sizeof("pa\n"))))
		pa(a,b);
	else if (!(ft_strncmp(cmd, "pb\n", sizeof("pb\n"))))
		pb(a,b);
	else
	{
		printf("Errror\n");
		exit(1);
	}
}


void	push_swap_bonus(t_stack **a, char **args, int argc)
{
	if (ft_strchr(args[0], ' '))
		handle_string(args[0], a);
	else
		handle_args(argc, args, a);
	
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
	{
		push_swap_bonus(&a, &argv[1], --argc);
		read_line(&a,&b);
		delete_lst(&a, lst_size(&a));
	}
}