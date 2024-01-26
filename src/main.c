/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/26 06:38:50 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char  *argv[])
{
    t_stack *a;
    //t_stack *b;

    a = NULL;
    if (argc < 2)  // if no numbers 
        return (ft_printf("Error\n"),1);
    else if (argc == 2) // if numbers char
        handle_string(argv[1], a);
    else if (argc >= 3) // if numbers int
        handle_args(argc - 1, &argv[1], a);//handle_nbrs(&a);
    return 0;
}