/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 23:03:50 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char  *argv[])
{
	t_stack *a;
	
	a = NULL;
    if (argc < 2)  // if no numbers 
		return (ft_printf("Error\n"),1);
  		//  else if (argc == 2) // if numbers char
		// handle_string(argv[1], &a);
    else if (argc >= 3)
    {
		handle_args(argc - 1, &argv[1], &a);
		if (argc == 4)
		{
			quick_sort(&a);
			
		}
	}
	//delete_lst((&a), lst_size(&a));
	return 0;
}
