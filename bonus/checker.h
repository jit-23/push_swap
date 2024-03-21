/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:05:45 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/03/21 14:31:37 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

void	delete_all(t_stack **a, t_stack **b);
void	read_line(t_stack **a, t_stack **b);
void	check_move(t_stack **a, t_stack **b, char *cmd);
void	push_swap_bonus(t_stack **a, char **args, int argc);

#endif