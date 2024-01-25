/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:19:20 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/25 03:38:09 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoll(char *nbr)
{
	int				i;
	int				signal;
	long long int	result;

	i = 0;
	signal = 1;
	result = 0;
	if (nbr[i] == 32 || (nbr[i] >= 7 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-')
	{
		signal = -1;
		i++;
	}
	if (nbr[i] == '-')
	{
		i++;
		printf("error");
		exit(1);
	}
	while (nbr[i])
		result = result * 10 + (nbr[i++] - '0');
	return (result * signal);
}
