/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertini <albertini@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:41:46 by falberti          #+#    #+#             */
/*   Updated: 2024/01/23 22:33:15 by albertini        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sets the best A node target for each B node 
// if nothing is bigger it take the smallest in a 
static	void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}	
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
	return ;
}

// Sets the price to move each nodes
void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (b->above_median == false)
			b->push_price = len_b - b->current_position;
		if (b->target_node->above_median == true)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - b->target_node->current_position;
		b = b->next;
	}
	return ;
}

// Sets the position of the node and if the node is above median or bellow
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	middlestack;

	i = 0;
	if (stack == NULL)
		return ;
	middlestack = stack_len(stack) / 2; //DEBUG
	while (stack)
	{
		stack->current_position = i;
		if (i <= middlestack)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
	return ;
}

// Sets the cheapest node of stack b
void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*best_match;
	long			cheapest_value;

	if (b == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < cheapest_value)
		{
			best_match = b;
			cheapest_value = b->push_price;
		}
		b = b->next;
	}
	best_match->cheapest = true;
	return ;
}

// Initialize node to be ready at the beginning or for a new operation
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
	return ;
}
