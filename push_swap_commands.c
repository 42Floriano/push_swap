/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:55:01 by falberti          #+#    #+#             */
/*   Updated: 2024/01/17 15:29:57 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(a[0]);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	tiny_sort(a);
	while (b[0])
	{
		init_nodes(a[0], b[0]);
		move_nodes(a, b);
	}
	set_current_position(a[0]);
	smallest = find_smallest(a[0]);
	if (smallest->above_median)
		while (a[0] !+ smallest)
			ra(a);
	else
		while (a[0] != smallest)
			rra(a);
}
