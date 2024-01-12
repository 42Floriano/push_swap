/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:28:41 by falberti          #+#    #+#             */
/*   Updated: 2024/01/11 17:15:32 by falberti         ###   ########.fr       */
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

// Main tester for nodes
/* int	main(void)
{
	t_stack_node	*a;

	a = NULL;
	char *v[5] = {v[0]= "42", v[1]= "100", v[2]= "-124", v[3]= NULL};
	stack_init(&a, v);
	while (a != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (42);
} */
