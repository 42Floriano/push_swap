/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:40:13 by falberti          #+#    #+#             */
/*   Updated: 2024/01/16 13:58:55 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	r_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(stack[0]);
	if (stack == NULL || stack[0] == NULL || len == 1)
		return ;
	last_node = find_last_node(stack[0]);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = stack[0];
	stack[0]->prev = last_node;
	stack[0] = last_node;
	return ;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
void	rra(t_stack_node **stacka)
{
	r_rotate(stacka);
	write(1, "rra\n", 4);
	return ;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
void	rrb(t_stack_node **stackb)
{
	r_rotate(stackb);
	write(1, "rrb\n", 4);
	return ;
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack_node **stacka, t_stack_node **stackb)
{
	r_rotate(stacka);
	r_rotate(stackb);
	write(1, "rrr\n", 4);
	return ;
}
