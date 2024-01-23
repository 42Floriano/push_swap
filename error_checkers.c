/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:07:16 by falberti          #+#    #+#             */
/*   Updated: 2024/01/23 15:06:36 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack_node **a, char **list)
{
	free_stack(a);
	free_list(list);
	write(2, "Error\n", 6);
	exit(1);
}

void	mini_error_free(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *to_check)
{
	int	i;

	i = 1;
	if (!((to_check[0] == '-' || to_check[0] == '+')
			|| (to_check[0] >= '0' && to_check[0] <= '9')))
		return (1);
	if (((to_check[0] == '-' || to_check[0] == '+')
			&& !(to_check[1] >= '0' && to_check[1] <= '9')))
		return (1);
	while (to_check[i])
	{
		if (!(to_check[i] >= '0' && to_check[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	int_repeat(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
