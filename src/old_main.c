/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:57:15 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/25 15:57:17 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
static int	create_stack(int *buff)
{
	int i = 0; 

	//t_stack *head;
	t_stack *new_node;
	t_stack *delete;
	//head = 0;
	new_node = (struct s_stack*)malloc(sizeof(t_stack));
	//head = new_node;
	delete = new_node;
	while(buff[i])
	{
		if (i == 0)
			new_node->x = buff[i];
		else
		{
			new_node->next = ft_lstnew(buff[i]);
			new_node = new_node->next;
		}
		i++;
	}
//	i = -1;
	//new_node->next = NULL;
//	t_stack *value;
	//value = head;
	/* while(buff[++i])
	{
		printf("%d\n", value->x);
		value = value->next;
	} */
	delete_lst(delete);
	return (0);
}

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
    while(buff_char[++i])
		free(buff_char[i]);
    free(buff_char);
    return 1;
}
int main(int argc, char  *argv[])
{
    t_stack a;

    if (argc < 2)
        return (ft_printf("Error\n"),1);
    if (argc == 2)
        split_stacks(&a, argv[1]);
    return 0;
}