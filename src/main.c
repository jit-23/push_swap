/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:53:56 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/21 22:19:55 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else
	{
		if (argc == 2 && argv[1][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		push_swap(&a, &b, &argv[1], --argc);
	}
	delete_lst(&a, lst_size(&a));
	return (0);
}
