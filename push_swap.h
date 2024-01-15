/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:23:30 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/15 19:38:43 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int				x;
    struct s_stack	*next;
}t_stack;//, t_stack_b;

# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

int  split_stacks(t_stack *stack, char *numbers);


#endif