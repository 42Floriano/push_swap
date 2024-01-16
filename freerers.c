/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:47 by falberti          #+#    #+#             */
/*   Updated: 2024/01/10 16:41:40 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || av[0] == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
