/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:39:57 by falberti          #+#    #+#             */
/*   Updated: 2024/01/15 17:41:14 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (2);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static	t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	highest = -2147483648;
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			higest_node = stack;
		}
			stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;
	t_stack_node	*temp;

	temp = *a;
	higest_node = find_highest(*a);
	if (temp == highest_node)
		ra(a);
	else if (temp->next == highest_node)
		rra(a);
	if (temp->value > temp->next->value)
		sa(a);
}

void 	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
	
	}
}
