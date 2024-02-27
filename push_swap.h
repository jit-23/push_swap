/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:23:30 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/02/23 12:24:04 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int				x;
	int				index;
	int				push_value;
	int				above_middle;
	struct s_stack	*match;
    struct s_stack	*next;
    struct s_stack	*prev;
}t_stack;

# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
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

t_stack *biggest_nbr(t_stack *head);
t_stack *smallest_nbr(t_stack *head); 
void 	quick_sort(t_stack **head);
int	lst_size(t_stack **head);
int sorted(t_stack **head);
void turk(t_stack **a, t_stack **b);//, int args);
void	big_match(t_stack **a, t_stack **b);
void push_value(t_stack *a, t_stack *b);// vou dar a cada node o valor do push do mesmo,  
t_stack	*cheappest_push(t_stack *b); // vou encontrar o primeiro node com o valor equivalente ao mais barato
void	r_till_top(t_stack **a, t_stack **b, t_stack *lowest_push);
void r_adjust(t_stack **a, t_stack **b, t_stack *lowest_push);
void	init_nodes(t_stack **a, t_stack **b);
void	move_nodes(t_stack **a, t_stack **b);


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