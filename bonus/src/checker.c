/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:07:54 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/20 02:02:30 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	read_line(t_stack **a, t_stack **b)
{
	char *line;

	line = " ";
	while(line)
	{
		line = get_next_line(0);
		check_move(line,a,b);
	}
	if (sorted(*a))
	{
		printf("OK");
	}
}
void	check_move(t_stack **a, t_stack **b, char *cmd)
{
	if (ft_strncmp(line, "sa\n", sizeof("sa\n")))
		sa(a);
	else if (ft_strncmp(line, "sb\n", sizeof("sb\n")))
		sb(b);
	else if (ft_strncmp(line, "ra\n", sizeof("ra\n")))
		ra(a);
	else if (ft_strncmp(line, "rb\n", sizeof("rb\n")))
		rb(b);
	else if (ft_strncmp(line, "rr\n", sizeof("rr\n")))
		rr(a,b);
	else if (ft_strncmp(line, "rra\n", sizeof("rra\n")))
		rra(a);
	else if (ft_strncmp(line, "rrb\n", sizeof("rrb\n")))
		rrb(b);
	else if (ft_strncmp(line, "rrr\n", sizeof("rrr\n")))
		rrr(a,b);
	else if (ft_strncmp(line, "pa\n", sizeof("pa\n")))
		pa(a,b);
	else if (ft_strncmp(line, "pb\n", sizeof("pb\n")))
		pb(a,b);
	else
	{
		printf("Error\n")
		exit(1);
	}
}

static void	push_swap_bonus(t_stack **a, t_stack **b, char **args, int argc)
{
	if (ft_strchr(args[0], ' '))
		handle_string(args[0], a);
	else
		handle_args(argc, args, a);
	
}

int main(int argc, char *argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	argc--;
	if (argc == 1)
		return (ft_printf("Error\n"),1);
	else if (argc == 2)
	{
		push_swap_bonus(&a,&b, &argv[1], argc);
		read_line(&a,&b);
	}
}