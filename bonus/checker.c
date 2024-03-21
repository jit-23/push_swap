/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:07:54 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/21 14:32:18 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_line(t_stack **a, t_stack **b)
{
	char	*line;

	line = " ";
	while (line)
	{
		line = get_next_line(0);
		if (line)
		{
			check_move(a, b, line);
			free(line);
		}
	}
	if (sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	push_swap_bonus(t_stack **a, char **args, int argc)
{
	if (ft_strchr(args[0], ' '))
		handle_string(args[0], a);
	else
		handle_args(argc, args, a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
	{
		push_swap_bonus(&a, &argv[1], --argc);
		read_line(&a, &b);
		delete_all(&a, &b);
	}
}
