/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:23:30 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/26 04:03:25 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int				x;
    struct s_stack	*next;
    struct s_stack	*prev;
}t_stack;

# include <stdio.h>
#include <limits.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

//int  split_stacks(t_stack *stack, char *numbers);
t_stack	*ft_lstnew(int x);
void	fill_stack(int *nbrs, t_stack *head, int size);
int	limit_value(int *nbrs, int size);
int *convert_arr(char **nbrs, int size);
void    handle_string(char *string, t_stack *a);
int repete_nbrs(int *nbr, int size);

//void	delete_nbrs(int *nbrs, int size);
void handle_args(int argc,char **argv, t_stack *a);
void delete_lst(t_stack *del, int size);


#endif