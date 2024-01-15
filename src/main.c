/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/15 19:45:11 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int  split_stacks(t_stack *stack, char *numbers)
{
    int i;
    char **buff_char;
    int *buff_int;

    i = -1;
    stack->next = 0;
    buff_char = ft_split(numbers, ' ');
    buff_int = (int *)malloc(sizeof(int) * ft_count(numbers, ' '));
    while(buff_char[++i])
        buff_int[i] = ft_atoi(buff_char[i]);
    i = -1;
    while(buff_int[++i])
        printf("%d\n", buff_int[i]);
    i = -1;
    while(buff_int[++i])    
        free(buff_int[i]);
    free(buff_int);
    return (0);
}

int main(int argc, char  *argv[])
{
    t_stack a;
    //t_stack *stack_b;
    if (argc != 2)
        return (ft_printf("wrong number of args\n"),1);
    split_stacks(&a, argv[1]);
    return 0;
}