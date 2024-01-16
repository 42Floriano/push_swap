/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:35:23 by falberti          #+#    #+#             */
/*   Updated: 2024/01/15 17:39:10 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_len(*stack);
	if (stack == NULL || stack[0] == NULL || len == 1)
		return ;
	last = find_last_node(stack[0]);
	last->next = stack[0];
	stack[0] = stack[0]->next;
	stack[0]->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

// ra (rotate a): Shift up all elements of stack a by 1.
void	ra(t_stack_node **stacka)
{
	rotate(stacka);
	write(1, "ra\n", 3);
	return ;
}

// rb (rotate b): Shift up all elements of stack b by 1.
void	rb(t_stack_node **stackb)
{
	rotate(stackb);
	write(1, "rb\n", 3);
	return ;
}

// rr : ra and rb at the same time.
void	rr(t_stack_node **stacka, t_stack_node **stackb)
{
	rotate(stacka);
	rotate(stackb);
	write(1, "rr\n", 3);
	return ;
}
