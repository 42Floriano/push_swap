/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:07:32 by falberti          #+#    #+#             */
/*   Updated: 2024/01/18 16:39:22 by falberti         ###   ########.fr       */
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

/*
 * tiny_sort sorts stack of 3 elements.
 * Finds the highest node then sorts the stacks
*/
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

/*
 * Handle_five sorts the  of 5 elements.
 * Pre-sorts stack a and pushes 2 nodes to stack b
*/
void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(a[0]) > 3)
	{
		init_nodes(a[0], b[0]);
		finish_rotation(a, find_smallest(a[0]), 'a');
		pb(b, a);
	}
	return ;
}
