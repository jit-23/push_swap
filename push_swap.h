/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:23:30 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/31 23:03:25 by fde-jesu         ###   ########.fr       */
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
# include <limits.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

//int  split_stacks(t_stack *stack, char *numbers);
t_stack	*ft_lstnew(int x);
void	fill_stack(int *nbrs, t_stack **head, int size);
int	limit_value(int *nbrs, int size);
int *convert_arr(char **nbrs, int size);
void    handle_string(char *string, t_stack **a);
int repete_nbrs(int *nbr, int size);

//void	delete_nbrs(int *nbrs, int size);
void handle_args(int argc,char **argv, t_stack **a);
void delete_lst(t_stack **del, int size);
t_stack	*ft_lstlast(t_stack *head);

t_stack *biggest_nbr(t_stack **head);
t_stack *smallest_nbr(t_stack **head); 
void 	quick_sort(t_stack **head);
int	lst_size(t_stack **head);
int sorted(t_stack **head);

void	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);

void	rotate(t_stack **head);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **a, t_stack **b);

void 	reverse_rotate(t_stack **head);
void 	rra(t_stack **head);
void 	rrb(t_stack **head);
void 	rrr(t_stack **a, t_stack **b);

void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **dest, t_stack **src);
void	pb(t_stack **dest, t_stack **src);

#endif