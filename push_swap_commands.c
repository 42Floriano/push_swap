/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:01 by falberti          #+#    #+#             */
/*   Updated: 2024/01/24 13:31:25 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate_both(t_stack_node **a,
							t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (a[0] != cheapest_node->target_node && b[0] != cheapest_node)
		rr(a, b);
	set_current_position(a[0]);
	set_current_position(b[0]);
	return ;
}

static	void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
									t_stack_node *cheapest_node)
{
	while (a[0] != cheapest_node->target_node && b[0] != cheapest_node)
		rrr(a, b);
	set_current_position(a[0]);
	set_current_position(b[0]);
	return ;
}

// This is the algorithm moving the nodes depending of 
// position in the stack and their cost.
static	void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(b[0]);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (cheapest_node->above_median == false
		&& cheapest_node->target_node->above_median == false)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
	return ;
}

// Finishes rotation till the n stack (cheapest) node is at the top
// of the define stack.
void	finish_rotation(t_stack_node **s, t_stack_node *n, char c)
{
	while (s[0] != n)
	{
		if (c == 'a')
		{
			if (n->above_median)
				ra(s);
			else
				rra(s);
		}
		else if (c == 'b')
		{
			if (n->above_median)
				rb(s);
			else
				rrb(s);
		}
	}
	return ;
}

// The function push_swap that handles 4 and more nodes.
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(a[0]);
	if (len_a == 5)
		handle_five(a, b);
	else
		while (len_a-- >= 3)
			pb(b, a);
	tiny_sort(a);
	while (b[0])
	{
		init_nodes(a[0], b[0]);
		move_nodes(a, b);
	}
	set_current_position(a[0]);
	smallest = find_smallest(a[0]);
	if (smallest->above_median)
		while (a[0] != smallest)
			ra(a);
	else
		while (a[0] != smallest)
			rra(a);
}
