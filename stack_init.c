/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:53:30 by falberti          #+#    #+#             */
/*   Updated: 2024/01/16 13:58:21 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long	ft_atol(char *str)
{
	long	nbr;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	nbr = 0;
	if (str[i] && str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] && str[i] == '+')
		i++;
	while (str[i])
		nbr = nbr * 10 + (str[i++] - 48);
	return (nbr * neg);
}

void	node_init(t_stack_node **a, char **list)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (list[i])
	{
		if (error_syntax(list[i]))
			error_free(a, list);
		nbr = ft_atol(list[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, list);
		if (int_repeat(*a, nbr))
			error_free(a, list);
		append_node(a, (int)nbr);
		i++;
	}
	free_list(list);
	return ;
}
