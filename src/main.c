/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/24 14:36:52 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char  *argv[])
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
    if (argc < 2)  // if no numbers
		return (ft_printf("Error\n"),1);
  		//  else if (argc == 2) // if numbers char
		//  handle_string(argv[1], &a);
	else if (argc == 3)
	{
		handle_args(argc - 1, &argv[1], &a);
		sorted(&a);
		sa(&a);
	}
    else if (argc > 3)
    {
		handle_args(argc - 1, &argv[1], &a);
		if (argc == 4)
			quick_sort(&a);
		else
		{
			turk(&a, &b);
		}
	}
	//printf("size --%d\n",  argc -1);
	//printf("size --%d\n",  lst_size(&a));
	//delete_lst((&a),);
	return 0;
}






	// while(b != NULL)
	// {
	// 	printf("b - %d\n", b->x);
	// 	b = b->next;
	// }
	// printf("--------\n");
	// while(a != NULL)
	// {
	// 	printf("a - %d\n", a->x);
	// 	a = a->next;
	// }