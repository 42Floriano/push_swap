/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:07:32 by falberti          #+#    #+#             */
/*   Updated: 2024/01/16 13:59:25 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next)
	{
		if (stack->value >= stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (a[0] == highest_node)
		ra(a);
	else if (a[0]->next == highest_node)
		rra(a);
	if (a[0]->value > a[0]->next->value)
		sa(a);
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	long			highest;

	if (stack == NULL)
		return (NULL);
	highest = LONG_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}
