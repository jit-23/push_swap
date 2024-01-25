/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:40:23 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/25 03:48:31 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void handle_args(int argc, char **argv, t_stack *a)
{
    int *nbrs;
    int i;

    i = -1;
    nbrs = (int *)malloc(sizeof(int) * (argc - 1));
    while(++i < argc - 1)
        nbrs[i] = argv[i];
    
    
}