/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:23:30 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/19 23:28:41 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

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

t_stack	*ft_lstnew(int x);
t_stack	*ft_lstlast(t_stack *head);
int		lst_size(t_stack **head);

void	fill_stack(long *nbrs, t_stack **head, int size);

int		limit_value(long *nbrs, int size);
int		not_int(char **argv);
int		repete_nbrs(long *nbr, int size);

void	handle_args(int argc, char **argv, t_stack **a);
void	handle_string(char *string, t_stack **a);

void	delete_lst(t_stack **del, int size);
void	delete_arr(char **arr);

void	init_head(t_stack *head);
void	quick_sort(t_stack **head);
int		sorted(t_stack *head);
t_stack	*biggest_nbr(t_stack *head);
t_stack	*smallest_nbr(t_stack *head);
t_stack	*find_cheappest_push(t_stack *b);
void	turk(t_stack **a, t_stack **b);
void	big_match(t_stack **a, t_stack **b);
void	small_match(t_stack **a, t_stack **b);

void	push_swap_string(t_stack **a, t_stack **b, int size);
void	push_swap_args(t_stack **a, t_stack **b, int argc);
void	push_swap(t_stack **a, t_stack **b, char **args, int argc);

void	push_value(t_stack *a, t_stack *b);
void	r_till_top(t_stack **a, t_stack **b, t_stack *lowest_push);
void	r_adjust(t_stack **a, t_stack **b,
			t_stack *lowest_push, char node_to_take);
void	init_nodes(t_stack **a, t_stack **b, char node2take);
void	put_index(t_stack *head, int middle);
void	move_a2b(t_stack **a, t_stack **b);
void	move_b2a(t_stack **a, t_stack **b);

void	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);

void	rotate(t_stack **head);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **a, t_stack **b);

void	reverse_rotate(t_stack **head);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **a, t_stack **b);

void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **dest, t_stack **src);
void	pb(t_stack **dest, t_stack **src);

void	rotate_dest_node(t_stack **dest_node, t_stack *n2p,
			char stack_to_give);
void	rotate_src_node(t_stack **src_node, t_stack *n2p,
			char stack_to_take);

#endif
